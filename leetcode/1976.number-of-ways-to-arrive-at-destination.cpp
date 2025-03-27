#include "headers.hpp"
#include <cstdint>

// @leet start
class Solution {
public:
    int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>> &roads) {
        // connected and simple
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int> &v : roads) {
            adj[v[0]].push_back({v[2], v[1]});
            adj[v[1]].push_back({v[2], v[0]});
        }

        vector<int64_t> minDist(n, INT64_MAX);
        vector<int64_t> ways(n, 0);
        minDist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>,
                       greater<pair<int64_t, int64_t>>>
            pq;

        pq.push({0, 0});
        while (!pq.empty()) {
            auto [dist, curr] = pq.top();
            pq.pop();
            for (auto [add, next] : adj[curr]) {
                int64_t newDist = add + dist;

                if (newDist > minDist[next])
                    continue;

                if (newDist < minDist[next]) {
                    ways[next] = 0;
                    pq.push({newDist, next});
                }

                minDist[next] = newDist;
                ways[next] = (ways[next] + ways[curr]) % MOD;
            }
        }
        return ways[n - 1];
    }
};
// @leet end
