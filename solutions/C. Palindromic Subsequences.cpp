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

// Problem: C. Palindromic Subsequences
// Contest: Codeforces Round 997 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2056/problems
// Memory Limit: 512
// Time Limit: 2000
// Start: Sat Feb  1 10:55:16 2025

using namespace std;
using ll = long long;
#define all(A) begin(A) end(A)

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    A[0] = A[1] = A[n - 1] = 1;
    for (int i = 2; i < n - 1; i++)
        A[i] = i;

    for (int val : A)
        cout << val << " ";
    cout << "\n";
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
