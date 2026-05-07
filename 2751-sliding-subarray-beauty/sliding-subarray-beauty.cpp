class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        multiset<int>st;
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]<0){
                st.insert(nums[j]);
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
            if(st.size()<x){ 
                ans.push_back(0);
            }
            else{
               auto it = st.begin();
                    advance(it, x-1);
                    ans.push_back(*it);
            
            }
            if(nums[i] < 0){
                    st.erase(st.find(nums[i]));
                }
            i++;
            j++;
            }
        }
        return ans;
    }
};