#include "headers.hpp"

// @leet start
class Solution {
public:
    vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> &ranges) {
        vector<pair<int, int>> res;
        res.push_back(ranges[0]);
        for (int i = 1; i < ranges.size(); i++) {
            auto [l, r] = ranges[i];
            auto &[backL, backR] = res.back();
            if (backR > l) {
                backR = max(backR, r);
            } else {
                res.push_back(ranges[i]);
            }
        }
        return res;
    }

    bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
        int m = rectangles.size();
        vector<pair<int, int>> horizontal;
        vector<pair<int, int>> vertical;
        for (vector<int> &v : rectangles) {
            horizontal.push_back({v[0], v[2]});
            vertical.push_back({v[1], v[3]});
        }
        sort(begin(horizontal), end(horizontal));
        sort(begin(vertical), end(vertical));

        horizontal = mergeIntervals(horizontal);
        vertical = mergeIntervals(vertical);

        return horizontal.size() >= 3 || vertical.size() >= 3;
    }
};
// @leet end
