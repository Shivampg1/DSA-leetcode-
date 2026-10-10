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
    int idx=i+1;
    while(idx<nums.size() && nums[idx]==nums[idx-1]){
        idx++;
    }
    solve(ans,nums,arr,idx);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          vector<vector<int>>ans;
          sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>arr;
        solve(ans,nums,arr,0);
        return ans;
    }
};