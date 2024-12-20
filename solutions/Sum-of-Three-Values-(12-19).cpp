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
    int64_t n, x;
    cin >> n >> x;
    vector<pair<int64_t, int>> nums(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums[i] = {val, i + 1};
    }

    sort(all(nums));
    for (int i = 0; i < n; i++) {
        x -= nums[i].first;

        int l = i + 1;
        int r = int(n - 1);

        while (l < r) {
            int64_t curr = nums[l].first + nums[r].first;
            if (curr < x) {
                l++;
            } else if (curr > x) {
                r--;
            } else {
                cout << nums[i].second << " " << nums[l].second << " "
                     << nums[r].second << "\n";
                return;
            }
        }

        x += nums[i].first;
    }
    cout << "IMPOSSIBLE\n";
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
