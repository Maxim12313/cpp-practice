#include "headers.hpp"

// @leet start
class Solution {
public:
    int longestNiceSubarray(vector<int> &nums) {
        int n = nums.size();
        int curr = 0;
        int l = 0;
        int maxLength = 0;
        for (int r = 0; r < n; r++) {
            while (l < r && (curr & nums[r])) {
                curr -= nums[l];
                l++;
            }
            curr += nums[r];
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
// @leet end
