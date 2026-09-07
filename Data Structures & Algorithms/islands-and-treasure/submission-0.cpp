class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && nrow < m &&
                    ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == INT_MAX) {

                    grid[nrow][ncol] = grid[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};