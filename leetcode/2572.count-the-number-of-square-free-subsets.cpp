#include "headers.hpp"

// @leet start
class Solution {
public:
    int MOD = 1e9 + 7;

    int squareFreeSubsets(vector<int> &nums) {
        // add prime factors each time
        // if any prime factor >= 2, then bad
        // nums[i] <= 30, very tiny
        // 1 <= n <= 10^3 small O(n^3) fine
        // bitmask dp
        // ways[mask][i] = ways[mask ^ factors][i - 1]
        vector<int> primes;
        for (int val = 2; val <= 30; val++) {
        }
    }
};
// @leet end
