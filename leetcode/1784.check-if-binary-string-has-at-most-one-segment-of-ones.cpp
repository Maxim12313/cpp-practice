#include "headers.hpp"

// @leet start
class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == '0' && s[i] == '1')
                count++;
        }
        if (s[0] == '1')
            count++;
        return count <= 1;
    }
};
// @leet end
