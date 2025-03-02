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

// Problem: Problem A - Candy Distribution
// Contest: UMPT Number Theory Praxis 1
// Judge: Kattis
// URL: https://open.kattis.com/contests/muarak/problems/candydistribution
// Memory Limit: 1024
// Time Limit: 1000
// Start: Sat Feb 15 12:26:36 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

struct Item {
    int64_t g, a, b;
    Item(int64_t g, int64_t a, int64_t b) : g(g), a(a), b(b) {}
};

Item gcd_extended(int64_t x, int64_t y) {
    if (y == 0)
        return Item(x, 1, 0);

    int64_t q = x / y;
    auto [g, a, b] = gcd_extended(y, x % y);
    int64_t newA = b;
    int64_t newB = a - b * q;
    return Item(g, newA, newB);
}

// ca = kx + 1 where k>0
// gcd(c, k) = 1
// ca - kx = 1
// c(a + qk) - k(x - qc) = 1 for int q
void solve() {
    int k, c;
    cin >> k >> c;
    auto [g, a, b] = gcd_extended(c, k);
    if (c == 1) {
        cout << k + 1 << "\n";
        return;
    }
    if (k == 1) {
        cout << 1 << "\n";
        return;
    }
    // since form (a + qk) for int q
    a = (a % k + k) % k;
    if (g > 1 || a > 1e9) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << a << "\n";
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
