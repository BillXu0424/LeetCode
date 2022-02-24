class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> prefix_sum(row, vector<int> (col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) {
                    prefix_sum[i][j] = mat[i][j];
                    continue;
                }
                if (i == 0) {
                    prefix_sum[i][j] = mat[i][j] + prefix_sum[i][j - 1];
                    continue;
                }
                if (j == 0) {
                    prefix_sum[i][j] = mat[i][j] + prefix_sum[i - 1][j];
                    continue;
                }
                prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + mat[i][j];
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int row_start = max(i - k, 0), row_end = min(i + k, row - 1), col_start = max(j - k, 0), col_end = min(j + k, col - 1);
                if(row_start == 0 && col_start == 0) {
                    mat[i][j] = prefix_sum[row_end][col_end];
                    continue;
                }
                if (row_start == 0) {
                    mat[i][j] = prefix_sum[row_end][col_end] - prefix_sum[row_end][col_start - 1];
                    continue;
                }
                if (col_start == 0) {
                    mat[i][j] = prefix_sum[row_end][col_end] - prefix_sum[row_start - 1][col_end];
                    continue;
                }
                mat[i][j] = prefix_sum[row_end][col_end] - prefix_sum[row_start - 1][col_end] - prefix_sum[row_end][col_start - 1] + prefix_sum[row_start - 1][col_start - 1];
            }
        }
        return mat;
    }
};