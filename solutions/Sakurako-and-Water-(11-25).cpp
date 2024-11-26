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
    vector<vector<int>> h(n, vector<int>(n));
    for (vector<int> &v : h)
        for (int &val : v)
            cin >> val;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int minVal = 0;
        for (int j = 0; j < n - i; j++) {
            minVal = min(minVal, h[j][i + j]);
        }
        if (minVal < 0)
            sum += -minVal;
    }
    for (int i = 1; i < n; i++) {
        int minVal = 0;
        for (int j = 0; j < n - i; j++) {
            minVal = min(minVal, h[i + j][j]);
        }
        if (minVal < 0)
            sum += -minVal;
    }
    cout << sum << "\n";
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
