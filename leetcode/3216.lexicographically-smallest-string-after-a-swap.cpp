#include "headers.hpp"

// @leet start
class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] % 2 != s[i - 1] % 2)
                continue;
            if (s[i - 1] <= s[i])
                continue;
            swap(s[i], s[i - 1]);
            break;
        }
        return s;
    }
};
// @leet end
