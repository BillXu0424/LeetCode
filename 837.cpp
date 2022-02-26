class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(k + maxPts, 0);
        for (int i = k; i <= min(k - 1 + maxPts, n); i++) dp[i] = 1;
        double sum = 0;
        for (int i = k; i <= k - 1 + maxPts; i++) sum += dp[i];
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = sum / maxPts;
            sum = sum - dp[i + maxPts] + dp[i];
        }
        return dp[0];
    }
};