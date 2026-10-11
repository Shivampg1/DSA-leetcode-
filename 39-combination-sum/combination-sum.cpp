class Solution {
public:
void solve(int i,vector<vector<int>>&ans,int n, int target,vector<int>& candidates,vector<int>&arr){
    if(i==n){
        if(target==0){
            ans.push_back(arr);
        }
        return;
    }
    if(candidates[i]<=target){
        arr.push_back(candidates[i]);
        solve(i,ans,n,target-candidates[i],candidates,arr);
        arr.pop_back();
    }
    solve(i+1,ans,n,target,candidates,arr);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0,ans,n,target,candidates,arr);
        return ans;
    }
};