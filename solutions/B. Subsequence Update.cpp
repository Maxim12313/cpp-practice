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

// Problem: B. Subsequence Update
// Contest: Codeforces Round 1000 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2063/problem/B
// Memory Limit: 256
// Time Limit: 1500
// Start: Thu Feb 27 23:50:41 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> A(n);
    for (int &val : A)
        cin >> val;

    r--;
    l--;
    multiset<int> left(begin(A), begin(A) + r + 1);
    multiset<int> right(begin(A) + l, end(A));

    int k = r - l + 1;

    int count = k;
    ll leftSum = 0;
    for (int val : left) {
        if (count-- == 0)
            break;
        leftSum += val;
    }

    ll rightSum = 0;
    count = k;
    for (int val : right) {
        if (count-- == 0)
            break;
        rightSum += val;
    }
    cout << min(leftSum, rightSum) << "\n";
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
