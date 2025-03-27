#include "headers.hpp"

// @leet start
class Solution {
public:
    bool works(vector<int> &dist, int mid, double hour) {
        double time = 0;
        // round up for all but the last
        for (int i = 0; i < dist.size() - 1; i++) {
            time += ceil(double(dist[i]) / mid);
        }
        time += double(dist.back()) / mid;
        return time <= hour;
    }

    int minSpeedOnTime(vector<int> &dist, double hour) {
        // can binary search on speed? since int
        // n log n * log n
        int lo = 0;
        int hi = 1e7;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // want the first true
            if (works(dist, mid, hour)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        // return lo if works else -1
        return works(dist, lo, hour) ? lo : -1;
    }
};
// @leet end
