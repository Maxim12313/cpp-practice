#include "headers.hpp"
#include <cstdint>

// @leet start
class Solution {
public:
    bool works(vector<int> &ranks, int64_t cars, int64_t mid) {
        // time = val * n * n
        // n = floor(sqrt(time / val))
        for (int64_t val : ranks) {
            cars -= floor(sqrt((double)mid / val));
        }
        return cars <= 0;
    }

    long long repairCars(vector<int> &ranks, int cars) {
        int64_t minRank = *min_element(begin(ranks), end(ranks));
        int64_t maxTime = minRank * cars * cars;

        int64_t lo = 0;
        int64_t hi = INT_MAX;
        while (lo < hi) {
            int64_t mid = lo + (hi - lo) / 2;
            if (works(ranks, cars, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
// @leet end
