class Solution {
public:

//  int solve(vector<vector<int>>& triangle,int n,int i,int j,vector<vector<int>> &dp){
//       if(i==n-1) return triangle[i][j];
//       if(dp[i][j]!=-1)return dp[i][j];
//       int left=triangle[i][j]+solve(triangle,n,i+1,j,dp);
//       int right=triangle[i][j]+solve(triangle,n,i+1,j+1,dp);
      
//       return dp[i][j]=min(left,right);
//   }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n=triangle.size();
        // int m=triangle[n-1].size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solve(triangle,n,0,0,dp);
          int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = n-1; i >= 0; i--) {

            for(int j = 0; j <= i; j++) {

                if(i == n-1) {
                    dp[i][j] = triangle[i][j];
                }
                else {
                    int down = triangle[i][j] + dp[i+1][j];

                    int diagonal = triangle[i][j] + dp[i+1][j+1];

                    dp[i][j] = min(down, diagonal);
                }
            }
        }

        return dp[0][0];
    }
};