#include "headers.hpp"

// @leet start
class Solution {
public:
    int minimumIndex(vector<int> &nums) {
        // can we try every index keeping track of left and right freq
        unordered_map<int, int> rightFreq;
        for (int val : nums)
            rightFreq[val]++;

        // could be left and right or left and total
        unordered_map<int, int> leftFreq;
        int maxFreqVal = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            leftFreq[nums[i]]++;
            rightFreq[nums[i]]--;

            // if tie, then this wouldn't be valid left anyways
            if (leftFreq[nums[i]] > leftFreq[maxFreqVal]) {
                maxFreqVal = nums[i];
            }

            int leftSize = i + 1;
            int rightSize = n - leftSize;

            // valid if left dominant and right dominant
            if (2 * leftFreq[maxFreqVal] > leftSize &&
                2 * rightFreq[maxFreqVal] > rightSize) {
                return i;
            }
        }
        return -1;
    }
};
// @leet end
