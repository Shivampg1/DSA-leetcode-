class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        int m=nums1.size();
        vector<int>arr(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                arr[i]=-1;
                st.push(nums2[i]);
            }
            else{
                arr[i]=st.top();
                st.push(nums2[i]);
            }
        }
        int j=0;
        vector<int>ans;
        for(int i=0;i<n && j<m ;i++){
            if(nums2[i]==nums1[j]){
                ans.push_back(arr[i]);
                j++;
                i=-1;
            }
        }
        return ans;
    }
};