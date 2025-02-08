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

// Problem: Array Division
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1085
// Memory Limit: 512
// Time Limit: 1000
// Start: Sat Feb  8 13:40:45 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

bool works(ll mid, vector<ll> &A, int k) {
    ll sum = 0;
    for (ll val : A) {
        if (val > mid)
            return false;

        if (val + sum > mid) {
            sum = 0;
            k--;
        }
        sum += val;
    }
    return k > 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (ll &val : A)
        cin >> val;

    ll lo = 0;
    ll hi = accumulate(all(A), ll(0)) + 1;
    while (lo < hi) {
        // first works
        ll mid = lo + (hi - lo) / 2;
        if (works(mid, A, k))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << "\n";
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
