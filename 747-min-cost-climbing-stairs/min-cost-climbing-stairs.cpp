class Solution {
public:
        vector<int> dp;
        int solve(vector<int>& cost,int n){
        if(dp.empty()) dp.resize(n+1,-1);
        if(n==0) 
        return cost[0];
        if(n==1)
        return cost[1];

        if(dp[n] != -1)
            return dp[n];
        
        dp[n]=cost[n]+min(solve(cost,n-1),solve(cost,n-2));
        return dp[n];
            
        }
         int minCostClimbingStairs(vector<int>& cost){
         int n=cost.size();
         return min(solve(cost,n-1),solve(cost,n-2));
    }
};