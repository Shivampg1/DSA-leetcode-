class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;

        for(auto s : strs){
            string temp= s;
            sort(temp.begin(),temp.end());
            freq[temp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it: freq){
            res.push_back(it.second);
        }
        return res;
    }
};