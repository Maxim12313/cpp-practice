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

// Problem: D. Subtract Min Sort
// Contest: Codeforces Round 998 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2060/problem/D
// Memory Limit: 256
// Time Limit: 2000
// Start: Sat Feb  1 01:12:34 2025

using namespace std;

#define all(A) begin(A) end(A)

bool works() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &val : A)
        cin >> val;

    for (int i = 1; i < n; i++) {
        int mini = min(A[i - 1], A[i]);
        A[i - 1] -= mini;
        A[i] -= mini;
        if (A[i - 1] > A[i])
            return false;
    }

    return true;
}

void solve() {
    cout << (works() ? "YES" : "NO") << "\n";
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
