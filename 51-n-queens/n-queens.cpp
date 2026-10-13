class Solution {
public:
    bool ispossible(int i, int j, int n, int m, vector<vector<string>>& mat) {
        for (int k = 0; k < n; k++) {
            if (mat[k][j] == "Q") {
                return false;
            }
        }
        for (int k = 0; k < m; k++) {
            if (mat[i][k] == "Q") {
                return false;
            }
        }
        int x = i + 1;
        int y = j - 1;
        while (x < n && y >= 0) {
            if (mat[x][y] == "Q") {
                return false;
            }
            x++;
            y--;
        }
        int p = i - 1;
        int r = j + 1;
        while (p >= 0 && r < m) {
            if (mat[p][r] == "Q") {
                return false;
            }
            p--;
            r++;
        }

        int a = i - 1;
        int b = j - 1;
        while (a >= 0 && b >= 0) {
            if (mat[a][b] == "Q") {
                return false;
            }
            a--;
            b--;
        }
        int t = i + 1;
        int u = j + 1;
        while (t < n && u < m) {
            if (mat[t][u] == "Q") {
                return false;
            }
            t++;
            u++;
        }
        return true;
    }
    void solve(int i, vector<vector<string>>& mat, int n, int m, int c,
               vector<vector<string>>& ans) {
        if (c == n) {
            vector<string> board;
            for (int r = 0; r < n; r++) {
                string row = "";
                for (int col = 0; col < m; col++) {
                    row += mat[r][col];
                }
                board.push_back(row);
            }

            ans.push_back(board);
            return;
        }
        if (i >= n)
            return;

        for (int j = 0; j < m; j++) {
            if (ispossible(i, j, n, m, mat)) {
                mat[i][j] = "Q";
                solve(i + 1, mat, n, m, c + 1, ans);
                mat[i][j] = ".";
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int m = n;
        vector<vector<string>> mat(n, vector<string>(m, "."));

        vector<vector<string>> ans;
        solve(0, mat, n, m, 0, ans);
        return ans;
    }
};