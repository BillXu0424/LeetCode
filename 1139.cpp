class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int dp[101][101][2] = {0};
        int row = grid.size(), col = grid[0].size(), max_size = 0;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (grid[i - 1][j - 1] == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                }
                else {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                }
            }
        }
        for (int i = row; i >= 1; i--) {
            for (int j = col; j >= 1; j--) {
                int sq_size = min(dp[i][j][0], dp[i][j][1]);
                if (sq_size == 0) continue;
                while (i - sq_size + 1 <= 0 || j - sq_size + 1 <= 0) {
                    sq_size--;
                }
                while (dp[i - sq_size + 1][j][0] < sq_size || dp[i][j - sq_size + 1][1] < sq_size) {
                    sq_size--;
                }
                max_size = max(max_size, sq_size);
            }
        }
        return max_size * max_size;
    }
};