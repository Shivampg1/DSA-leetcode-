class Solution {
public:
    bool isValid(int i, int j, int r, int c) {
        return (i >= 0 && j >= 0 && i < r && j < c);
    }

    void dfs(int x, int y, vector<vector<bool>>& visited,
             vector<vector<int>>& heights, int r, int c) {
        visited[x][y] = 1;
        int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int k = 0; k < 4; k++) {
            int newX = x + dirs[k][0];
            int newY = y + dirs[k][1];
            if (isValid(newX, newY, r, c) && !visited[newX][newY] &&
                heights[newX][newY] >= heights[x][y]) {
                dfs(newX, newY, visited, heights, r, c);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>> PacificVis(r, vector<bool>(c, false));
        vector<vector<bool>> AtlanticVis(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++) {
            dfs(i, 0, PacificVis, heights, r, c);
            dfs(i, c - 1, AtlanticVis, heights, r, c);
        }
        for (int i = 0; i < c; i++) {
            dfs(0, i, PacificVis, heights, r, c);
            dfs(r - 1, i, AtlanticVis, heights, r, c);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (PacificVis[i][j] && AtlanticVis[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};