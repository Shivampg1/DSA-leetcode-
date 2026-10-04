class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int max_val=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                max_val=max(max_val,count);
            }
            else if(s[i]==')'){
                count--;
                if(count<0) count=0;
            }
            else{
                continue;
            }
        }
        return max_val;
    }
};