#include "headers.hpp"

// @leet start
class Solution {
public:
    bool works(int mid, int m, vector<int> &position) {
        int prev = -mid;
        for (int pos : position) {
            if (pos - prev >= mid) {
                prev = pos;
                m--;
            }
        }
        return m <= 0;
    }

    int maxDistance(vector<int> &position, int m) {
        sort(begin(position), end(position));

        int lo = 0;
        int hi = position.back() - position[0];
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (works(mid, m, position)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
// @leet end
