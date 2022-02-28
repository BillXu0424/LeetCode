class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int sum = 0;
        int n = wall.size(), res = 0;
        unordered_map<int, int> hm;
        for (int i = 0; i < n; i++) {
            int m = wall[i].size();
            sum = 0;
            for (int j = 0; j < m - 1; j++) {
                sum += wall[i][j];
                if (hm.count(sum) == 1) hm[sum]++;
                else hm[sum] = 1; 
            }
        }
        for (auto it = hm.begin(); it != hm.end(); it++) {
            if (it->second > res) res = it->second;
        }
        return n - res;
    }
};