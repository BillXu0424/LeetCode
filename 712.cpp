class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = len1 - 1; i >= 0; i--) {
            dp[i][len2] = dp[i + 1][len2] + s1[i];
        }
        for (int j = len2 - 1; j >= 0; j--) {
            for (int i  = len1; i >= 0; i--) {
                if (i == len1) {
                    dp[i][j] = dp[i][j + 1] + s2[j];
                    continue;
                }
                if (s1[i] != s2[j]) {
                    dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
                }
                else dp[i][j] = dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};