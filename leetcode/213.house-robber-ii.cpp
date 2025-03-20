#include "headers.hpp"

// @leet start
class Solution {
public:
    // [l, r)
    int robFrom(vector<int> &nums, int l, int r) {
        int prevMax = 0;
        int currMax = nums[l];
        for (int i = l + 1; i < r; i++) {
            int res = max(prevMax + nums[i], currMax);
            prevMax = currMax;
            currMax = res;
        }
        return currMax;
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(robFrom(nums, 1, n), robFrom(nums, 0, n - 1));
    }
};
// @leet end
