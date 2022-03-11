class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int k = 0, row = mat.size(), col = mat[0].size();
        bool dir_up = true;
        int i = 0, j = 0;
        while (k <= row + col - 2) {
            res.emplace_back(mat[i][j]);
            if (j == col - 1) {
                if (dir_up) {
                    i++;
                    dir_up = false;
                    k++;
                    continue;
                }
            }
            if (j == 0) {
                if (!dir_up) {
                    if (i == row - 1) {
                        k++;
                        dir_up = true;
                        j++;
                        continue;
                    }
                    else {
                        k++;
                        dir_up = true;
                        i++;
                        continue;
                    }
                }
            }
            if (i == 0) {
                if (dir_up) {
                    if (j == col - 1) {
                        i++;
                        dir_up = false;
                        k++;
                        continue;
                    }
                    else {
                        j++;
                        dir_up = false;
                        k++;
                        continue;
                    }
                }
            }
            if (i == row - 1) {
                if (!dir_up) {
                    k++;
                    dir_up = true;
                    j++;
                    continue;
                }
            }

            if (dir_up) {
                i--;
                j++;
            }
            else {
                i++;
                j--;
            }
        }
        return res;
    }
};