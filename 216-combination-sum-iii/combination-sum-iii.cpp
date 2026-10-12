class Solution {
public:
void solve(int i,vector<int>nums,vector<vector<int>>&ans,vector<int>&arr,int k,int n,int sum){
    if(i==nums.size()){
        if(arr.size()==k && sum==n){
            ans.push_back(arr);
        }
        return;
    }
    sum+=nums[i];
    arr.push_back(nums[i]);

    solve(i+1,nums,ans,arr,k,n,sum);
    arr.pop_back();

    sum-=nums[i];
    solve(i+1,nums,ans,arr,k,n,sum);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<int>arr;
        vector<vector<int>>ans;
        solve(0,nums,ans,arr,k,n,0);
        return ans;
    }
};