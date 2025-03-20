#include "headers.hpp"
#include <compare>

// @leet start
class Solution {
public:
    void dfs(vector<int> &component, vector<vector<pair<int, int>>> &adj,
             int curr, int color) {
        for (auto [next, val] : adj[curr]) {
            if (component[next] != -1)
                continue;
            component[next] = color;
            dfs(component, adj, next, color);
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>> &edges,
                            vector<vector<int>> &query) {

        // path is non increasing
        // longest path is always best

        vector<vector<pair<int, int>>> adj(n);
        for (vector<int> &v : edges) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }

        int color = 0;
        vector<int> component(n, -1);
        for (int i = 0; i < n; i++) {
            if (component[i] != -1)
                continue;
            int andVal = INT_MAX;
            component[i] = color;
            dfs(component, adj, i, color);
            color++;
        }

        vector<int> colorVal(color, INT_MAX);

        for (vector<int> &v : edges) {
            int color = component[v[0]];
            colorVal[color] &= v[2];
        }

        vector<int> ans;
        for (vector<int> &v : query) {
            int color = component[v[0]];
            if (color != component[v[1]])
                ans.push_back(colorVal[color]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
// @leet end
