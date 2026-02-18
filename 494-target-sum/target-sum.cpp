class Solution {
public:
    int subset(vector<int> nums,int s1){
        int n= nums.size();
         vector<vector<int>> dp(n+1, vector<int>(s1+1,0));

         dp[0][0]=1;

         for(int i=1;i<=n;i++){
            for(int j=0;j<=s1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
         }
         return dp[n][s1];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
       int s1;
       int sum=0;

       for(int i=0;i<nums.size();i++){
        sum += nums[i];
       }

       s1=(sum+target)/2;

       if(abs(target)>sum) return 0;

       if((sum+target)%2 != 0) return 0;


       return subset(nums,s1);
    }
};