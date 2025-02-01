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

// Problem: E. Graph Composition
// Contest: Codeforces Round 998 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2060/problem/E
// Memory Limit: 256
// Time Limit: 2000
// Start: Sat Feb  1 01:12:34 2025

using namespace std;

#define all(A) begin(A) end(A)

class DSU {
public:
    int count;
    vector<int> rep;

    DSU(int n) : count(n) {
        rep.resize(n);
        iota(begin(rep), end(rep), 0);
    }

    int find(int a) {
        if (rep[a] == a)
            return a;
        return rep[a] = find(rep[a]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            count--;
        if (a > b)
            swap(a, b);
        rep[b] = a;
    }
};

void solve() {
    // bidirectional
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> F(m1), G(m2);
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        F[i] = make_pair(a - 1, b - 1);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        G[i] = make_pair(a - 1, b - 1);
    }

    DSU dsuG(n);
    for (auto [a, b] : G)
        dsuG.unite(a, b);

    DSU dsuF(n);
    int count = 0;
    for (auto [a, b] : F) {
        // need to erase from F
        if (dsuG.find(a) != dsuG.find(b))
            count++;
        else
            dsuF.unite(a, b);
    }
    // need to add to F
    count += dsuF.count - dsuG.count;
    cout << count << "\n";
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
