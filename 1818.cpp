class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), max = 0, result;
        long sum = 0;
        int lb, ub, closest;
        vector<int> abs_diff(n);
        vector<int> nums1_sorted = nums1;
        sort(nums1_sorted.begin(), nums1_sorted.end());
        for (int i = 0; i < n; i++) {
            abs_diff[i] = abs(nums1[i] - nums2[i]);
            lb = nums1_sorted[lower_bound(nums1_sorted.begin(), nums1_sorted.end(), nums2[i]) - nums1_sorted.begin()];
            ub = nums1_sorted[upper_bound(nums1_sorted.begin(), nums1_sorted.end(), nums2[i]) - nums1_sorted.begin()];
            if (abs(nums2[i] - lb) < abs(nums2[i] - ub)) closest = lb;
            else closest = ub;
            if (abs_diff[i] - abs(nums2[i] - closest) > max) max = abs_diff[i] - abs(nums2[i] - closest);
            sum += abs_diff[i];
        }
        return (int) ((sum - max) % 1000000009);
    }
};