class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long>> rowPrefix(n, vector<long>(m));
        vector<vector<long>> colPrefix(n, vector<long>(m));
        vector<vector<long>> leftDiagPrefix(n, vector<long>(m));
        vector<vector<long>> rightDiagPrefix(n, vector<long>(m));

        buildPrefixArrays(n, m, grid, rowPrefix, colPrefix, leftDiagPrefix, rightDiagPrefix);

        int maxSide = min(n, m);

        while (maxSide > 1) {
            if (foundMagicSquare(n, m, maxSide, rowPrefix, colPrefix, leftDiagPrefix, rightDiagPrefix)) {
                return maxSide;
            }
            maxSide--;
        }

        return 1;
    }

private:
    void buildPrefixArrays(int n, int m, vector<vector<int>>& grid,
                          vector<vector<long>>& rowPrefix, vector<vector<long>>& colPrefix,
                          vector<vector<long>>& leftDiagPrefix, vector<vector<long>>& rightDiagPrefix) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowPrefix[i][j] = (j == 0) ? grid[i][j] : rowPrefix[i][j - 1] + grid[i][j];
                colPrefix[i][j] = (i == 0) ? grid[i][j] : colPrefix[i - 1][j] + grid[i][j];
                leftDiagPrefix[i][j] = (i == 0 || j == 0) ? grid[i][j] : leftDiagPrefix[i - 1][j - 1] + grid[i][j];
                rightDiagPrefix[i][j] = (i == 0 || j == m - 1) ? grid[i][j] : rightDiagPrefix[i - 1][j + 1] + grid[i][j];
            }
        }
    }

    bool foundMagicSquare(int n, int m, int size, vector<vector<long>>& rowPrefix,
                         vector<vector<long>>& colPrefix, vector<vector<long>>& leftDiagPrefix,
                         vector<vector<long>>& rightDiagPrefix) {
        for (int i = 0; i <= n - size; i++) {
            for (int j = 0; j <= m - size; j++) {
                if (isMagicSquare(i, j, size, rowPrefix, colPrefix, leftDiagPrefix, rightDiagPrefix)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isMagicSquare(int row, int col, int size, vector<vector<long>>& rowPrefix,
                      vector<vector<long>>& colPrefix, vector<vector<long>>& leftDiagPrefix,
                      vector<vector<long>>& rightDiagPrefix) {
        int endRow = row + size - 1;
        int endCol = col + size - 1;
        
        long targetSum = rowPrefix[row][endCol] - (col > 0 ? rowPrefix[row][col - 1] : 0);

        for (int r = row; r <= endRow; r++) {
            if (rowPrefix[r][endCol] - (col > 0 ? rowPrefix[r][col - 1] : 0) != targetSum) {
                return false;
            }
        }

        for (int c = col; c <= endCol; c++) {
            if (colPrefix[endRow][c] - (row > 0 ? colPrefix[row - 1][c] : 0) != targetSum) {
                return false;
            }
        }

        long leftDiagSum = leftDiagPrefix[endRow][endCol];
        if (row > 0 && col > 0) leftDiagSum -= leftDiagPrefix[row - 1][col - 1];
        if (leftDiagSum != targetSum) return false;

        long rightDiagSum = rightDiagPrefix[endRow][col];
        if (row > 0 && endCol < rowPrefix[0].size() - 1) rightDiagSum -= rightDiagPrefix[row - 1][endCol + 1];
        
        return rightDiagSum == targetSum;
    }
};