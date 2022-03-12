class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size(), res = 0;
        vector<int> candies(len, 1);
        set<int> low;
        if (len == 1) return 1;
        for (int i = 0; i < len; i++) {
            if (i == 0 && ratings[i] < ratings[i + 1])  {
                low.insert(i);
                continue;
            }
            if (i == len - 1 && ratings[i] < ratings[i - 1]) {
                low.insert(i);
                continue;
            }
            if ((ratings[i] < ratings[i + 1] && ratings[i] <= ratings[i - 1]) || (ratings[i] <= ratings[i + 1] && ratings[i] < ratings[i - 1])){
                low.insert(i);
            }
        }
        int k;
        if (low.empty()) return len;
        for (int n : low) {
            if (n == 0) {
                k = 1;
                while (ratings[k] > ratings[k - 1]) {
                    candies[k] = max(candies[k], candies[k - 1] + 1);
                    k++;
                }
                continue;
            }
            if (n == len - 1) {
                k = len - 2;
                while (ratings[k] > ratings[k + 1]) {
                    candies[k] = max(candies[k], candies[k + 1] + 1);
                    k--;
                }
                continue;
            }
            k = n - 1;
            while (ratings[k] > ratings[k + 1]) {
                candies[k] = max(candies[k], candies[k + 1] + 1);
                k--;
                if (k == -1) break;
            }
            
            k = n + 1;
            while (ratings[k] > ratings[k - 1]) {
                candies[k] = max(candies[k], candies[k - 1] + 1);
                k++;
                if (k == len) break;
            }
        }
        for (int i = 0; i < len; i++) {
            res += candies[i];
        }
        return res;
    }
};