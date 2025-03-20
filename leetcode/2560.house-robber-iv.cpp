#include "headers.hpp"

// @leet start
class Solution {
public:
    bool works(vector<int> &nums, int mid, int k) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] <= mid) {
                k--;
                i += 2;
            } else {
                i++;
            }
        }
        return k <= 0;
    }

    int minCapability(vector<int> &nums, int k) {
        int n = nums.size();
        int lo = 0;
        int hi = 1e9;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (works(nums, mid, k))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
// @leet end
