class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {

        int n = matrix.size();
        int m = matrix[0].size();

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int ans = 1;
        if (row - 1 >= 0 && matrix[row - 1][col] > matrix[row][col]) {
            ans = max(ans, 1 + solve(row - 1, col, matrix, dp));
        }

        if (row + 1 < n && matrix[row + 1][col] > matrix[row][col]) {
            ans = max(ans, 1 + solve(row + 1, col, matrix, dp));
        }

        if (col - 1 >= 0 && matrix[row][col - 1] > matrix[row][col]) {
            ans = max(ans, 1 + solve(row, col - 1, matrix, dp));
        }

        if (col + 1 < m && matrix[row][col + 1] > matrix[row][col]) {
            ans = max(ans, 1 + solve(row, col + 1, matrix, dp));
        }

        return dp[row][col] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }

        return ans;
    }
};