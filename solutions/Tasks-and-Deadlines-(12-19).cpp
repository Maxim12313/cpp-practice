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

void solve() {
    // do as many tasks as possible
    // early + late = on time + on time
    // just want fewest active
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        tasks[i] = {a, d};
        // sort by duration
    }
    sort(all(tasks));

    int64_t reward = 0;
    int64_t time = 0;
    for (auto [a, d] : tasks) {
        time += a;
        reward += d - time;
    }
    cout << reward << "\n";
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
