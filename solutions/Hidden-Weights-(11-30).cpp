#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <pthread.h>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adjList[u].push_back({w, v});
        adjList[v].push_back({-w, u});
    }
    // can set backwards too
    // next - curr = weight
    // curr - next = -weight

    // every scc can be adjusted freely afterwards
    // not possible if 2 point into same and not same
    vector<bool> visited(n, false);
    vector<int64_t> color(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        st.push(i);
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            for (auto [weight, next] : adjList[curr]) {
                if (visited[next])
                    continue;
                visited[next] = true;
                // next - curr = weight
                color[next] = color[curr] + weight;
                st.push(next);
            }
        }
    }
    for (int64_t val : color)
        cout << val << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
