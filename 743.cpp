class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, int>>> g(n);
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k - 1);
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (dist[x] < time) {
                continue;
            }
            for (auto &e : g[x]) {
                int y = e.first, d = dist[x] + e.second;
                if (d < dist[y]) {
                    dist[y] = d;
                    q.emplace(d, y);
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};