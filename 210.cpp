class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_deg(numCourses, 0), order;
        queue<int> q;
        int len = prerequisites.size();
        for (int i = 0; i < len; i++) {
            in_deg[prerequisites[i][0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (in_deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            order.emplace_back(v);
            for (int i = 0; i < len; i++) {
                if (prerequisites[i][1] == v) {
                    in_deg[prerequisites[i][0]]--;
                    if (in_deg[prerequisites[i][0]] == 0) q.push(prerequisites[i][0]);
                }
            }
        }
        if (order.size() < numCourses) return vector<int>();
        return order;
    }
};