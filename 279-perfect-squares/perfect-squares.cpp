class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  

        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }

        for (int i = 1; i <= n; ++i) {
            for (int square : squares) {
                if (i < square) break;
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }

        return dp[n];
    }
};