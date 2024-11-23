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

int maxMake(vector<int> &a, int idx) {
    int n = a.size();
    unordered_map<int, int> pairFreq;
    int maxSize = 0;
    int l = idx;
    for (int r = idx; r < n; r += 2) {
        if (a[r - 1] != a[r]) {
            l = r + 2;
            pairFreq = unordered_map<int, int>();
        } else {
            pairFreq[a[r]]++;
        }

        while (l <= r && pairFreq[a[r]] >= 2) {
            pairFreq[a[l]]--;
            l += 2;
        }
        maxSize = max(maxSize, r - l + 2);
    }
    return maxSize;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &val : a)
        cin >> val;

    int candA = maxMake(a, 1);
    int candB = maxMake(a, 2);
    cout << max(candA, candB) << "\n";
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
