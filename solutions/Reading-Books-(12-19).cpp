#include <algorithm>
#include <cassert>
#include <cfenv>
#include <climits>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <pthread.h>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define all(v) begin(v), end(v)

template <typename A> string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> times(n);
    for (int &val : times)
        cin >> val;
    sort(all(times));
    int64_t maxVal = times[n - 1];
    int64_t leftSum = accumulate(begin(times), end(times) - 1, 0LL);
    if (maxVal < leftSum) {
        // if not limiting, then can follow each other perfectly
        cout << maxVal + leftSum << "\n";
    } else {
        // if maxVal is limiter, then just 2 of it
        cout << 2 * maxVal << "\n";
    }
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
