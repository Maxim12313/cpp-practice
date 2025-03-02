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

// Problem: Movie Festival II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1632
// Memory Limit: 512
// Time Limit: 1000
// Start: Sat Feb 15 18:04:36 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies[i] = {a, b};
    }
    sort(all(movies));

    multiset<int> times;
    for (int i = 0; i < k; i++)
        times.insert(0);

    int count = 0;
    for (auto [l, r] : movies) {
        auto low = begin(times);
        auto high = prev(end(times));
        if (*low <= l) {
            count++;
            times.erase(low);
            times.insert(r);
        } else if (r < *high) {
            times.erase(high);
            times.insert(r);
        }
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
