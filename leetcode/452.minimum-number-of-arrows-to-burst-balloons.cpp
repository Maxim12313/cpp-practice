#include "headers.hpp"

// @leet start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        // minimize l,r
        int n = points.size();
        sort(begin(points), end(points));

        vector<int> ends = {points[0][1]};
        for (int i = 1; i < n; i++) {
            vector<int> &curr = points[i];
            int &last = ends.back();
            if (last >= curr[0])
                last = min(last, curr[1]);
            else
                ends.push_back(curr[1]);
        }
        return ends.size();
    }
};
// @leet end
