class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         stack<int>st;
        int n=nums.size();
         vector<int>arr(n);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                arr[i%n]=-1;
                st.push(nums[i%n]);
            }
            else{
                arr[i%n]=st.top();
                st.push(nums[i%n]);
            }
        }
        return arr;
    }
};