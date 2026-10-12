class Solution {
public:

bool ispalindrome(string s){
string s2=s;
reverse(s2.begin(),s2.end());
return s==s2;
}

void solve(int i,int n,vector<string> &arr,string s,vector<vector<string>> &ans){
  if(i==n){
    ans.push_back(arr);
    return;
  }

  for(int idx=i;idx<n;idx++){
    string part=s.substr(i, idx - i + 1);
    if(ispalindrome(part)){
      arr.push_back(part);
      solve(idx+1,n,arr,s,ans);
      arr.pop_back();
    }
  }
}
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string>arr;
        vector<vector<string>>ans;
        solve(0,n,arr,s,ans);
        return ans;
    }
};