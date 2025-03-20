#include "headers.hpp"

// @leet start
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string t;
        string p;
        int i = 0;
        vector<char> minAhead(n);
        minAhead[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--)
            minAhead[i] = min(minAhead[i + 1], s[i]);

        while (i < s.size()) {
            if (t.empty() || t.back() > minAhead[i]) {
                t += s[i];
                i++;
            } else {
                p += t.back();
                t.pop_back();
            }
        }
        while (!t.empty()) {
            p += t.back();
            t.pop_back();
        }
        return p;
    }
};
// @leet end
