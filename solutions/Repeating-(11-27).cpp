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
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &val : h)
        cin >> val;

    unordered_map<int, int> prevIdx;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = prevIdx[h[i]] - 1;
        prevIdx[h[i]] = i + 2;
    }
    for (int val : ans)
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
