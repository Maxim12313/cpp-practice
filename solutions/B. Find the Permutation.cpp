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

// Problem: B. Find the Permutation
// Contest: Codeforces Round 997 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2056/problems
// Memory Limit: 256
// Time Limit: 1500
// Start: Sat Feb  1 10:55:16 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

void solve() {
    int n;
    cin >> n;
    vector<string> G(n);
    for (string &s : G) {
        cin >> s;
    }
    vector<int> perm(n);
    iota(all(perm), 0);

    auto comp = [&](int a, int b) {
        if (G[a][b] == '1') {
            return a < b;
        }
        return a > b;
    };

    sort(all(perm), comp);
    for (int val : perm)
        cout << val + 1 << " ";
    cout << "\n";
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
