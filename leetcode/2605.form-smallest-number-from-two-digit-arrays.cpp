#include "headers.hpp"
#include <algorithm>

// @leet start
class Solution {
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set1(begin(nums1), end(nums1));
        int minBoth = 99;
        for (int val : nums2)
            if (set1.count(val))
                minBoth = min(minBoth, val);

        int min1 = *min_element(begin(nums1), end(nums1));
        int min2 = *min_element(begin(nums2), end(nums2));

        int combined = min(min1, min2) * 10 + max(min1, min2);
        return min(combined, minBoth);
    }
};
// @leet end
