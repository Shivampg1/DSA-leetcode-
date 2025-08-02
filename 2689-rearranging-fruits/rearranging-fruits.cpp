class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]--;

        vector<int> extra1, extra2;
        int globalMin = min(*min_element(basket1.begin(), basket1.end()),
                            *min_element(basket2.begin(), basket2.end()));
        for (auto& [num, diff] : freq) {
            if (diff % 2 != 0) return -1;
            int count = abs(diff) / 2;
            if (diff > 0)
                extra1.insert(extra1.end(), count, num);
            else if (diff < 0)
                extra2.insert(extra2.end(), count, num);
        }


        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        long long cost = 0;
        for (size_t i = 0; i < extra1.size(); ++i) {
            int a = extra1[i];
            int b = extra2[i];
            cost += min(2 * globalMin, min(a, b));
        }

        return cost;
    }
};