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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int64_t, int64_t>> A(n);
    for (auto &[a, b] : A)
        cin >> a;
    for (auto &[a, b] : A)
        cin >> b;

    sort(begin(A), end(A));

    int64_t minVal = INT64_MAX;
    multiset<int64_t> set;
    int64_t currSum = 0;
    for (int i = 0; i < n; i++) {
        auto [a, b] = A[i];
        currSum += b;
        set.insert(b);
        if (size(set) > k) {
            auto it = prev(end(set));
            currSum -= *it;
            set.erase(it);
        }
        if (size(set) == k)
            minVal = min(minVal, currSum * a);
    }
    cout << minVal << "\n";
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
