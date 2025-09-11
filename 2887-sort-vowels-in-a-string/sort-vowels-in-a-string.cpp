class Solution {
public:
    string sortVowels(string s) {
        set<char>p{'A','E','I','O','U'};
        set<char>c{'a','e','i','o','u'};
        vector<int>ans;
        vector<char> res;
        vector<int>index;

        for(int i=0;i<s.length();i++){
            if(p.find(s[i])!=p.end() || c.find(s[i])!=c.end()){
                int ascii=int(s[i]);
                index.push_back(i);
                ans.push_back(ascii);
            }
            // else{
            //     return s;
            // }
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            char ch=char(ans[i]);
            res.push_back(ch);
        }
        for(int i=0;i<index.size();i++){
            s[index[i]]=res[i];
        }
        return s;
    }
};