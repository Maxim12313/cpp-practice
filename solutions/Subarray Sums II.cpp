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

// Problem: Subarray Sums II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1661
// Memory Limit: 512
// Time Limit: 1000
// Start: Sat Feb  8 12:09:43 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> A(n);
    for (ll &val : A)
        cin >> val;
    map<ll, ll> sumFreq;
    sumFreq[0] = 1;
    ll count = 0;
    ll sum = 0;
    for (ll val : A) {
        sum += val;
        count += sumFreq[sum - x];
        sumFreq[sum]++;
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
