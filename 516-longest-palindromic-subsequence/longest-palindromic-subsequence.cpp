class Solution {
public:

int length(string &s, string &s2, int n, int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];

            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();
        int m=s2.size();

        return length(s,s2,n,m);
    }
};