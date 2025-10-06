class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        using pii = pair<int, pair<int, int>>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto [t, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();
            
            if (r == n - 1 && c == n - 1) return t;
            
            for (int i = 0; i < 4; i++) {
                int row = r + dr[i], col = c + dc[i];
                if (row >= 0 && row < n && col >= 0 && col < n) {
                    int newTime = max(t, grid[row][col]);
                    if (newTime < dist[row][col]) {
                        dist[row][col] = newTime;
                        pq.push({newTime, {row, col}});
                    }
                }
            }
        }
        
        return -1;
    }
};