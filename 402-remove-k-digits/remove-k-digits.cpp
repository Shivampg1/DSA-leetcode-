class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string ans="";
        if(k==n){
            return "0";
        }
       
    int s=num.size();
      stack<char>st;
      for(int i=0;i<s;i++){
        while(!st.empty() && k!=0 && num[i]<st.top()){
            st.pop();
            k--;
        }
        if(st.empty()){
            st.push(num[i]);
        }
        else{
            st.push(num[i]);
        }
      }
      while (k > 0 && !st.empty()) {
       st.pop();
       k--;
      }
      while(!st.empty()){
        ans+=st.top();
        st.pop();
      }
 
      reverse(ans.begin(),ans.end());
      int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
          if (ans.empty()) ans = "0";
      return ans;

    }
};