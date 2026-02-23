class Solution {
public:

int number(string &word1, string &word2,int n,int m){

vector<vector<int>> dp(n+1,vector<int>(m+1,0));

for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(word1[i-1]==word2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
        }
        else{
            dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
int res=dp[n][m];

int s1=n-res;
int s2=m-res;
return s1+s2;
}

    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        return number(word1,word2,n,m);
    }
};