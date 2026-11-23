class Solution {
public:

int solve(vector<int>&arr,int i,vector<int>&dp){
      int n=arr.size();
      if(i==0) return arr[i];
      if(i<0)return 0;

      if(dp[i]!=-1)return dp[i];

      int pik=arr[i]+solve(arr,i-2,dp);
      int notpik=0+solve(arr,i-1,dp);
      return dp[i]=max(pik,notpik);
  }
    int rob(vector<int>& arr) {
         int n=arr.size();
          vector<int>dp(n,-1);
          vector<int>dp2(n,-1);
          vector<int>temp,temp2;
          if(n==1) return arr[0];
          for(int i=0;i<n;i++){
              if(i!=0) temp.push_back(arr[i]);
              if(i!=n-1) temp2.push_back(arr[i]);
          }
          int ans1= solve(temp,n-2,dp);
          int ans2=solve(temp2,n-2,dp2);
          
          return max(ans1,ans2);
    }
};