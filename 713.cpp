class MySolution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        int i = 0, j = -1, prod = 1, last = -1, res = 0;
        while (j < size) {
            if (j < size - 1 && prod * nums[j + 1] < k) {
                prod *= nums[j + 1];
                j++;
            }
            else {
                prod = 1;
                if (j <= last) {
                    j = i++;
                }
                else {
                    res = res + mysum(j - i + 1) - mysum(last - i + 1);
                    last = j;
                    j = i++;
                }
            }
            if (last == size - 1) break;
        }
        return res;
    }

    int mysum(int n) {
        return (1 + n) * n / 2;
    }
};

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0, left = 0, size = nums.size();
        for (int right = 0; right < size; right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
    }
};