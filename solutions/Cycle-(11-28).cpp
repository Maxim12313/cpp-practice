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
    // 0 out, 1 in
    vector<vector<int>> adjList[2];
    adjList[0].resize(n);
    adjList[1].resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[0][u].push_back(v);
        adjList[1][v].push_back(u);
    }

    vector<bool> visited[2];
    visited[0].resize(n, false);
    visited[1].resize(n, false);

    int steps[2];
    steps[0] = steps[1] = 0;

    queue<int> q[2];
    q[0].push(0);
    q[1].push(0);

    int i = 0;
    while (!q[i].empty()) {
        int sz = size(q[i]);
        while (sz--) {
            int curr = q[i].front();
            q[i].pop();
            if (visited[i][curr])
                continue;
            visited[i][curr] = true;

            if (curr != 0 && visited[!i][curr]) {
                cout << steps[0] + steps[1] - 1 << "\n";
                return;
            }

            for (int next : adjList[i][curr])
                q[i].push(next);
        }
        steps[i]++;
        i = !i;
    }
    cout << -1 << "\n";
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
