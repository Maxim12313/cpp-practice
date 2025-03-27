#include "headers.hpp"

// @leet start
class Solution {
public:
    void separate(string &s, string &even, string &odd) {
        for (int i = 0; i < s.size(); i++) {
            (i % 2 == 0 ? even : odd) += s[i];
        }
    }

    vector<int> getFreq(string &s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        return freq;
    }

    bool makeSame(string &s1, string &s2) {
        // return true;
        auto a = getFreq(s1);
        auto b = getFreq(s2);
        return a == b;
    }

    bool checkStrings(string s1, string s2) {
        // same parity idx are swapped
        string even1, odd1;
        separate(s1, even1, odd1);
        string even2, odd2;
        separate(s2, even2, odd2);

        return makeSame(even1, even2) && makeSame(odd1, odd2);
    }
};
// @leet end
