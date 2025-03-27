#include "headers.hpp"

// @leet start
class Solution {
public:
    int getHigh(vector<int> &nums) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (int val : nums) {
            minVal = min(minVal, val);
            maxVal = max(maxVal, val);
        }
        return maxVal - minVal;
    }

    bool works(vector<int> &nums, int p, int mid) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] <= mid) {
                p--;
                i++;
            }
        }
        return p <= 0;
    }

    int minimizeMax(vector<int> &nums, int p) {
        sort(begin(nums), end(nums));

        int lo = 0;
        int hi = getHigh(nums);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (works(nums, p, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
// @leet end
