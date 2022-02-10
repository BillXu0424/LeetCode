class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) { // dynamic programming
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        for (int k = 1; k <= m; k++) {
            for (int i = 0; i <= k; i++) {
                if (i == 0) dp[i][k - i] = dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1];
                else if (i == k) dp[i][k - i] = dp[i - 1][k - i] + nums[i - 1] * multipliers[k - 1];
                else dp[i][k - i] = max(dp[i][k - i - 1] + nums[n - k + i] * multipliers[k - 1], dp[i - 1][k - i] + nums[i - 1] * multipliers[k - 1]);
            }
        }
        int max = dp[0][m];
        for (int i = 0; i <= m; i++) {
            if (max < dp[i][m - i]) max = dp[i][m - i];
        }
        return max;
    }
};