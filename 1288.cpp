bool cmp(const vector<int> &i1, const vector<int> &i2) {
    if (i1[0] < i2[0]) return true;
    else if (i1[0] > i2[0]) return false;
    else {
        if (i1[1] > i2[1]) return true;
        else return false;
    }

}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int length = intervals.size(), i = 1;
        vector<vector<int>> res;
        res.emplace_back(intervals[0]);
        while (i < length) {
            if (intervals[i][1] > res.back()[1]) res.emplace_back(intervals[i]);
            i++;
        }
        return res.size();
    }
};