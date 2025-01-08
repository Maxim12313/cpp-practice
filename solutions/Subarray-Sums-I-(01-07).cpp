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
#include <type_traits>
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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int &val : arr)
        cin >> val;

    int count = 0;
    int64_t sum = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        sum += arr[r];
        while (l <= r && sum > x) {
            sum -= arr[l];
            l++;
        }
        if (sum == x)
            count++;
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
