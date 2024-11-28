#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <deque>
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

struct Range {
    int l, r, j;
    bool operator<(const Range &o) const {
        if (l != o.l)
            return l < o.l;
        return r > o.r;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r, i};
    }
    sort(begin(ranges), end(ranges));
    vector<bool> contains(n, false), contained(n, false);

    int closestEnd = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        auto [l, r, j] = ranges[i];
        if (r >= closestEnd)
            contains[j] = true;
        closestEnd = min(closestEnd, r);
    }

    int furthestEnd = -1;
    for (auto [l, r, j] : ranges) {
        if (r <= furthestEnd)
            contained[j] = true;
        furthestEnd = max(furthestEnd, r);
    }

    for (bool val : contains)
        cout << val << " ";
    cout << "\n";

    for (bool val : contained)
        cout << val << " ";
    cout << "\n";
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
