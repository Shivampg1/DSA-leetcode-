class Solution {
public:
    string largestOddNumber(string num) {
        string res="";
        int n=num.size();
        int val=-1;
        for(int i=n-1;i>=0;i--){
            if(num[i]%2!=0){
                val=i;
                break;
            }
        }
        if(val!=-1){
          for(int i=0;i<=val;i++){
            res+=num[i];
          }
        }
        return res;
    }
};