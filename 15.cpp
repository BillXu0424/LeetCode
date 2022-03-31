class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3) return res;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[len - 1] < 0) return res;
        if (nums[0] == nums[len - 1]) {
            res.emplace_back(vector<int> {0, 0, 0});
            return res;
        }
        for (int i = 1; i < len - 1; i++) {
            int l = 0, r = len - 1;
            if (i != 1 && nums[i] == nums[i - 1]) l = i - 1;
            while (l < i && r > i) {
                if (nums[l] + nums[i] + nums[r] == 0) {
                    if (res.empty()) res.emplace_back(vector<int> {nums[l], nums[i], nums[r]});
                    if (res.back()[0] != nums[l] || res.back()[2] != nums[r]) {
                        res.emplace_back(vector<int> {nums[l], nums[i], nums[r]});
                    } 
                    l++;
                    r--;
                }
                else if (nums[l] + nums[i] + nums[r] > 0) r--;
                else l++;
            }
        }
        return res;
    }
};