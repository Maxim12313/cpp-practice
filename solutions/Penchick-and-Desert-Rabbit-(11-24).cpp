#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
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

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &val : h)
        cin >> val;

    // can always reach max to left by default
    vector<int> ans(n);
    ans[0] = h[0];
    for (int i = 1; i < n; i++)
        ans[i] = max(h[i], ans[i - 1]);

    // if exists smaller val in right range than left max, then we can land on
    // i+1
    int rightMin = h[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        int leftMax = ans[i];
        if (leftMax > rightMin)
            ans[i] = ans[i + 1];
        rightMin = min(rightMin, h[i]);
    }
    for (int val : ans)
        cout << val << ' ';
    cout << '\n';
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
