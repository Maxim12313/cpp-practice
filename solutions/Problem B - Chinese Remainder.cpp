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

// Problem: Problem B - Chinese Remainder
// Contest: UMPT Number Theory Praxis 1
// Judge: Kattis
// URL: https://open.kattis.com/contests/muarak/problems/chineseremainder
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

void solve() {
    ll a, n, b, m;
    cin >> a >> n >> b >> m;
    ll k = n * m;
    auto [g, nn, mm] = gcd_extended(n, m);
    ll partA = a * mm % n * m; // a * mm * m % k;
    ll partB = b * nn % m * n;
    ll x = (partA + partB + k) % k;
    cout << x << " " << k << "\n";
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
