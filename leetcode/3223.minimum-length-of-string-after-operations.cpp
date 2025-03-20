#include "headers.hpp"

// @leet start
class Solution {
public:
    int minimumLength(string s) {
        // 1, 2, if exists of each char
        vector<int> charFreq(26, 0);
        for (char c : s)
            charFreq[c - 'a']++;

        int length = 0;
        for (int val : charFreq) {
            // if 0, add 0
            // if even, ret 2
            // if odd, ret 1
            if (val == 0)
                continue;

            if (val % 2 == 0)
                length += 2;
            else
                length += 1;
        }
        return length;
    }
};
// @leet end
