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

// Problem: D. Unique Median
// Contest: Codeforces Round 997 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2056/problems
// Memory Limit: 512
// Time Limit: 2000
// Start: Sat Feb  1 10:55:17 2025

using namespace std;
using ll = long long;
#define all(A) begin(A) end(A)

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &val : A)
        cin >> val;

    ll bad = 0;
    for (int cand = 1; cand <= 10; cand++) {
        vector<int> B(n);
        for (int i = 0; i < n; i++)
            B[i] = A[i] <= cand ? -1 : 1;

        vector<int> presum(n + 1);
        presum[0] = 0;
        for (int i = 1; i <= n; i++)
            presum[i] = presum[i - 1] + B[i - 1];

        unordered_map<int, int> sumFreq;
        ll count = 0;
        int j = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i - 1] == cand) {
                while (j < i) {
                    sumFreq[presum[j]]++;
                    j++;
                }
            }
            int curr = presum[i];
            count += sumFreq[curr];
        }
        bad += count;
    }
    ll ans = ll(n) * (n + 1) / 2 - bad;
    cout << ans << "\n";
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
