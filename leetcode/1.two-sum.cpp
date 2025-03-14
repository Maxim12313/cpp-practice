#include "headers.hpp"

// @leet start
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> prev;
        for (int i = 0; i < size(nums); i++) {
            int other = target - nums[i];
            if (prev.count(other)) {
                return {prev[other], i};
            }
            prev[nums[i]] = i;
        }

        return {-1, -1};
    }
};
// @leet end
