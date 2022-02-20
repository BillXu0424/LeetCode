class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int length = nums.size();
        nth_element(nums.begin(), nums.begin() + length / 2, nums.end());
        int det = nums[length / 2], cost = 0;
        for (int i = 0; i < length; i++) {
            cost += abs(nums[i] - det);
        }
        return cost;
    }
};