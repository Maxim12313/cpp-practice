#include "headers.hpp"
#include <algorithm>

// @leet start
class Solution {
public:
    string kthDistinct(vector<string> &arr, int k) {
        unordered_map<string, int> freq;
        for (string &s : arr)
            freq[s]++;

        for (string &s : arr) {
            k -= int(freq[s] == 1);
            if (k == 0)
                return s;
        }
        return "";
    }
};
// @leet end
