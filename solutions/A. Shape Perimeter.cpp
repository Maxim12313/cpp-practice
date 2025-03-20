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

// Problem: A. Shape Perimeter
// Contest: Codeforces Round 997 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2056/problems
// Memory Limit: 256
// Time Limit: 1000
// Start: Sat Feb  1 10:55:16 2025

using namespace std;
using ll = long long;
#define all(A) begin(A) end(A)

void solve() {

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> move(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        move[i] = {a, b};
    }
    int perimiter = 4 * m;
    for (int i = 1; i < n; i++) {
        auto [x, y] = move[i];
        perimiter += 2 * x + 2 * y;
    }
    cout << perimiter << "\n";
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
