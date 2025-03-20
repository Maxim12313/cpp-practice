#include "headers.hpp"

// @leet start
class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> seen;
        for (int i = 1; i < s.size(); i++) {
            string curr = string() + s[i - 1] + s[i];
            seen.insert(curr);

            swap(curr[0], curr[1]);
            if (seen.count(curr))
                return true;
        }
        return false;
    }
};
// @leet end
