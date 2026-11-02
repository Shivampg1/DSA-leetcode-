class Solution {
public:
    int totalFruit(vector<int>& s) {
        int n=s.size();
        unordered_map<int, int> mp;
        int max_val = INT_MIN;
        int i = 0;
        int j = 0;

        while (j < n) {
            mp[s[j]]++;

            if (mp.size() <= 2) {
                max_val = max(max_val, j - i + 1);
                j++;
            } else if (mp.size() > 2) {
                while (mp.size() > 2) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return max_val;
    }
};