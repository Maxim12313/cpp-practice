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

// Problem: Subarray Distinct Values
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2428
// Memory Limit: 512
// Time Limit: 1000
// Start: Sat Feb  8 13:36:30 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &val : A)
        cin >> val;
    ll count = 0;
    map<int, int> numFreq;
    int l = 0;
    for (int r = 0; r < n; r++) {
        numFreq[A[r]]++;
        while (l <= r && size(numFreq) > k) {
            numFreq[A[l]]--;
            if (numFreq[A[l]] == 0)
                numFreq.erase(A[l]);
            l++;
        }
        count += r - l + 1;
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
