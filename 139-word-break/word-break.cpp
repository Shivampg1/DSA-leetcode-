class Solution {
public:
bool solve(int i,string s,unordered_set<string> &set,vector<int>&dp){
    if(i==s.size()){
        return true;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    string ans="";
    for(int j=i;j<s.size();j++){
        ans+=s[j];
        if(set.find(ans)!=set.end()){
            if(solve(j+1,s,set,dp)){
                return dp[i]=true;
            }
        }
    }
    return dp[i]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
       return solve(0,s,set,dp);

    }
};