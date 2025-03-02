#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// Problem: C. Remove Exactly Two
// Contest: Codeforces Round 1000 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2063/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: Thu Feb 27 23:50:41 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

void solve() {
    int n;
    cin >> n;
    vector<unordered_set<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    multiset<int> set;
    for (unordered_set<int> &v : adj)
        set.insert(size(v));

    int best = 0;
    for (int i = 0; i < n; i++) {

        // take out
        int curr = size(adj[i]);
        set.erase(set.find(curr));
        for (int next : adj[i]) {
            int old = size(adj[next]);
            set.erase(set.find(old));
            set.insert(old - 1);
        }

        int second = *prev(end(set));
        best = max(best, curr + second - 1);

        // put back
        set.insert(curr);
        for (int next : adj[i]) {
            int old = size(adj[next]);
            set.erase(set.find(old - 1));
            set.insert(old);
        }
    }
    cout << best << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
