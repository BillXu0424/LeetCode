class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len));
        for (int i = 0; i < len; i++)
            dp[i][i] = true;
        if (len > 1) {
            for (int i = 1; i < len; i++) { // dynamic programming
                for (int j = 0; j < len - i; j++) { // principle diag
                    if (s[j] == s[j + i]) {
                        if (i == 1) dp[j][j + i] = true;
                        else dp[j][j + i] = dp[j + 1][j + i - 1];
                    }
                    else
                        dp[j][j + i] = false;
                }
            }
        }
        vector<vector<string>> partition;
        vector<string> part;
        backtrack(dp, partition, part, 0, s); // backtrack
        return partition;
    }

    void backtrack(vector<vector<bool>> dp, vector<vector<string>> &partition, vector<string> part, int start, string s) {
        if (start == s.length()) {
            partition.push_back(part);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (dp[start][i]) {
                part.push_back(s.substr(start, i - start + 1)); 
                backtrack(dp, partition, part, i + 1, s);
                part.pop_back();
            }
        }
    }
};