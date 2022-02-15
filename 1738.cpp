class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix(m, vector<int>(n));
        vector<int> arr;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    prefix[i][j] = matrix[i][j];
                    arr.emplace_back(prefix[i][j]);
                    continue;
                }
                if (i == 0) {
                    prefix[i][j] = prefix[i][j - 1] ^ matrix[i][j];
                    arr.emplace_back(prefix[i][j]);
                    continue;
                }
                if (j == 0) {
                    prefix[i][j] = prefix[i - 1][j] ^ matrix[i][j];
                    arr.emplace_back(prefix[i][j]);
                    continue;
                }
                prefix[i][j] = prefix[i - 1][j] ^ prefix[i][j - 1] ^ prefix[i - 1][j - 1] ^ matrix[i][j];
                arr.emplace_back(prefix[i][j]);
            }
        }
        nth_element(arr.begin(), arr.begin() + k - 1, arr.end(), greater<int>());
        return arr[k - 1];
    }
};