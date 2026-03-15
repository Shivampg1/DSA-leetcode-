class Solution {
public:

    bool isPalindrome(string s) {
        string f;
    for (char a : s) {
        if (isalnum(a)) { 
            f += tolower(a); 
        }
    }
        int st=0;
        int e=f.size()-1;
        while(st<=e){
            if(f[st]!=f[e]){
                return 0;
            }
            else{
                st++;
                e--;
            }
        }
        return 1;
        
    }
};