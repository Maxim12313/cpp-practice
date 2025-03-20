#include "headers.hpp"

// @leet start
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
        int idx = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            int x2 = points[i][0];
            int y2 = points[i][1];
            if (x2 != x && y2 != y)
                continue;

            int dist = abs(x2 - x) + abs(y2 - y);
            if (dist < minDist) {
                idx = i;
                minDist = dist;
            }
        }
        return idx;
    }
};
// @leet end
