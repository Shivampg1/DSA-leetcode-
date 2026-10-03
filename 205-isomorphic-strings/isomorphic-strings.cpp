class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp1;
        map<char,char>mp2;
        int n=s.size();
        for(int i=0;i<n;i++){
            char fs=s[i];
            char ls=t[i];

            if(mp1.find(fs)!=mp1.end()){
               if(mp1[fs]!=ls){
                return false;
               }
            }
            else{
                mp1[fs]=ls;
            }
            if(mp2.find(ls)!=mp2.end()){
               if(mp2[ls]!=fs){
                return false;
               }
            }
            else{
                mp2[ls]=fs;
            }

        }
        return true;
    }
};