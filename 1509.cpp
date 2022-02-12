class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), min_diff = nums[n - 1] - nums[0];
        if (n <= 4) return 0;
        min_diff = min(nums[n - 1] - nums[3], min_diff); // 3F
        min_diff = min(nums[n - 2] - nums[2], min_diff); // 2F1E
        min_diff = min(nums[n - 3] - nums[1], min_diff); // 1F2E
        min_diff = min(nums[n - 4] - nums[0], min_diff); // 3E
        return min_diff;
    }
};