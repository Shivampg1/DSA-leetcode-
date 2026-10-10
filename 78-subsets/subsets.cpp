class Solution {
public:
void solve(vector<vector<int>>&ans,vector<int>nums,vector<int>&arr,int i){
    if(i==nums.size()){
        ans.push_back(arr);
        return;
    }
    arr.push_back(nums[i]);
    solve(ans,nums,arr,i+1);
    arr.pop_back();
    solve(ans,nums,arr,i+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>arr;
        solve(ans,nums,arr,0);
        return ans;
    }
};