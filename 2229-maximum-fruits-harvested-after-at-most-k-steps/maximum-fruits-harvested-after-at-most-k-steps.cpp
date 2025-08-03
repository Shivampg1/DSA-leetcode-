class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
      int n = fruits.size();
        vector<int> pos(n), prefixSum(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            pos[i] = fruits[i][0];
            prefixSum[i + 1] = prefixSum[i] + fruits[i][1];
        }

        auto getLeftIdx = [&](int limit) {
            return lower_bound(pos.begin(), pos.end(), limit) - pos.begin();
        };

        auto getRightIdx = [&](int limit) {
            return upper_bound(pos.begin(), pos.end(), limit) - pos.begin() - 1;
        };

        int maxFruit = 0;

        for (int x = 0; x <= k; ++x) {
            int leftMost = startPos - x;
            int remainingSteps = k - x;
            int rightMost = startPos + max(0, remainingSteps - x);
            int l = getLeftIdx(leftMost);
            int r = getRightIdx(rightMost);

            if (l <= r && r < n) {
                maxFruit = max(maxFruit, prefixSum[r + 1] - prefixSum[l]);
            }
        }

        for (int x = 0; x <= k; ++x) {
            int rightMost = startPos + x;
            int remainingSteps = k - x;
            int leftMost = startPos - max(0, remainingSteps - x); 

            int l = getLeftIdx(leftMost);
            int r = getRightIdx(rightMost);

            if (l <= r && r < n) {
                maxFruit = max(maxFruit, prefixSum[r + 1] - prefixSum[l]);
            }
        }

        return maxFruit;
    }
};