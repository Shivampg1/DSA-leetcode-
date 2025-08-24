class Solution {
public:
    string frequencySort(string s) {
        vector<int>str(128,0);
        for(char c : s) str[c]++;
        sort(s.begin(),s.end(), [&](char a,char b){
            return str[a] >str[b] || (str[a]==str[b] && a<b);
        });
        return s;
    }
};