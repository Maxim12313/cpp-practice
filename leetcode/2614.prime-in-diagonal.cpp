#include "headers.hpp"

// @leet start
class Solution {
public:
    bool isPrime(int val) {
        if (val <= 1)
            return false;

        for (int i = 2; i * i <= val; i++) {
            if (val % i == 0)
                return false;
        }
        return true;
    }

    int diagonalPrime(vector<vector<int>> &nums) {
        int n = nums.size();
        int maxPrime = 0;
        for (int i = 0; i < n; i++) {
            int other = n - i - 1;
            if (isPrime(nums[i][i]))
                maxPrime = max(maxPrime, nums[i][i]);
            if (isPrime(nums[i][other]))
                maxPrime = max(maxPrime, nums[i][other]);
        }
        return maxPrime;
    }
};
// @leet end
