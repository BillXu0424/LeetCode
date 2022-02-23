class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> prefix(row + 1,vector<int>(col + 1, 0));
        int max_l = 0;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                int l = max_l + 1;
                while (i + l - 1 <= row && j + l - 1 <= col) {
                    if (prefix[i + l - 1][j + l - 1] - prefix[i - 1][j + l - 1] - prefix[i + l - 1][j - 1] + prefix[i - 1][j - 1] > threshold) break;
                    max_l++;
                    l++;
                }
            }
        }
        return max_l;
    }
};