class Solution {
public:
    int maxFreqSum(string s) {
        set<char> p{'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> freq;
        unordered_map<char,int> con;
        // int sum=0;
        for (char c : s) {

            if (p.find(c) != p.end()) {
                freq[c]++;
            }
        }
        int max_sum = 0;
        for (const auto& p : freq) {
            max_sum = max(max_sum, p.second);
        }
        // return max_sum;
        // return 0;
        for (char t : s) {

            if (p.find(t) == p.end()) {
                con[t]++;
            }
        }
        int max_consonant = 0;
        for (const auto& pair : con) {
            max_consonant = max(max_consonant, pair.second);
        }
        return (max_sum + max_consonant);
    }
};