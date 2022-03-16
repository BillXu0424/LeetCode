class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int len = prices.size();
        long long count = len;
        if (len == 1) return count;
        int start = 0, end = 1;
        while (end < len) {
            if (prices[end] == prices[end - 1] - 1) end++;
            else {
                count += cum_sum(end - start - 1);
                start = end;
                end++;
            }
        }
        if (end != start + 1) {
            count += cum_sum(end - start - 1);
        }
        return count;
    }

    long long cum_sum(long long gap) {
        return (1 + gap) * gap / 2;
    }
};