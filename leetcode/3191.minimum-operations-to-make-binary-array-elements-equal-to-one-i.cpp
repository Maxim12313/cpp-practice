#include "headers.hpp"

// @leet start
class Solution {
public:
    int minOperations(vector<int> &nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i + 2 < n; i++) {
            if (nums[i] != 1) {
                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                count++;
            }
        }
        if (nums[n - 1] & nums[n - 2] & nums[n - 3])
            return count;
        return -1;
    }
};
// @leet end
