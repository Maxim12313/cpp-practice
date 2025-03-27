#include "headers.hpp"

// @leet start
class Solution {
public:
    bool works(int n, int mid, vector<int> &quantities) {
        for (int val : quantities) {
            n -= ceil(val / double(mid));
        }
        return n >= 0;
    }

    int minimizedMaximum(int n, vector<int> &quantities) {
        int lo = 1;
        int hi = *max_element(begin(quantities), end(quantities));
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (works(n, mid, quantities)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
// @leet end
