class Solution {
public:
    int maxProfit(vector<int>& nums, int orders) {
        sort(nums.begin(), nums.end(), greater<int>());
        long res = 0, mod = 1e9 + 7;
        int j = 0;
        while(orders > 0) {
            while(j < nums.size() && nums[j] >= nums[0]) {
                ++j;
            }
            int next = 0;
            if(j < nums.size()) {
                next = nums[j];
            }
            long bucks = j, delta = nums[0] - next;
            long rem = bucks * delta;
            if(rem > orders) {
                long dec = orders / bucks;
                long a1 = nums[0] - dec + 1, an = nums[0];
                res += (((a1 + an) * dec) / 2) * bucks;
                res += (nums[0] - dec) * (orders % bucks);
            } 
            else {
                long a1 = next + 1, an = nums[0];
                res += (((a1 + an) * delta) / 2) * bucks;
                nums[0] = next;
            }
            orders -= rem;
            res %= mod;
        }
        return res;
    }
};