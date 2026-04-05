class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},
        {'D',500},{'M',1000}};

        //or
        // unordered_map<char,int> st;
        // st['I'] = 1 ;
        // st['V'] = 5 ;
        // st['X'] = 10 ; 
        // st['L'] = 50 ; 
        // st['C'] = 100; 
        // st['D'] = 500; 
        // st['M'] = 1000;

        int res=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]<mp[s[i+1]]){
                res -= mp[s[i]];
            }
            else{
                res += mp[s[i]];
            }
        }
        return res;
    }
};