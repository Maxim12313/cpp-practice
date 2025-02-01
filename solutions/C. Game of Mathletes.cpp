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

// Problem: C. Game of Mathletes
// Contest: Codeforces Round 998 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2060/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: Sat Feb  1 01:12:34 2025

using namespace std;

#define all(A) begin(A) end(A)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &val : A)
        cin >> val;

    unordered_map<int, int> numFreq;
    int score = 0;
    for (int val : A) {
        if (numFreq[k - val] > 0) {
            numFreq[k - val]--;
            score++;
        } else {
            numFreq[val]++;
        }
    }
    cout << score << "\n";
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
