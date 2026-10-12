class Solution {
public:

void solve(int i,vector<string>&ans,string digits,int n,string &s,vector<string>mp){
    if(i==n){
        ans.push_back(s);
        return;
    }
    string str=mp[digits[i]-'0'];
    for(char ch:str){
        s.push_back(ch);
        solve(i+1,ans,digits,n,s,mp);
        s.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string>ans;
        string s="";
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,ans,digits,n,s,mp);
        return ans;
    }
};