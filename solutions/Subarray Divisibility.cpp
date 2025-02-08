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

// Problem: Subarray Divisibility
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1662
// Memory Limit: 512
// Time Limit: 1000
// Start: Sat Feb  8 13:22:42 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

void solve() {
    int n;
    cin >> n;
    vector<ll> A(n);
    for (ll &val : A)
        cin >> val;
    vector<ll> modFreq(n, 0);
    modFreq[0] = 1;
    ll count = 0;
    ll modSum = 0;
    for (ll val : A) {
        modSum = (modSum + val % n + n) % n;
        count += modFreq[modSum];
        modFreq[modSum]++;
    }
    cout << count << "\n";
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
