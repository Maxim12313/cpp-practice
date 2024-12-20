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

template <typename A, typename B> string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

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

bool works(vector<int> &times, int64_t needed, int64_t t) {
    for (int val : times) {
        t -= needed / val;
        if (t <= 0)
            break;
    }
    return t <= 0;
}

void solve() {
    int64_t n, t;
    cin >> n >> t;
    vector<int> times(n);
    for (int &val : times)
        cin >> val;

    // nlogn binary search working time
    int64_t lo = 0;
    int64_t hi = t * *min_element(all(times));
    while (lo < hi) {
        int64_t mid = lo + (hi - lo) / 2;
        if (works(times, mid, t))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << hi << "\n";
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
