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

void fillRange(vector<int> &ans, int l, int r, int &fill) {
    for (int i = l + 1; i <= r; i += 2) {
        ans[i - 1] = ans[i] = fill++;
    }
}

void solve() {
    int n;
    cin >> n;
    // 1 4 9 16 25 36 49 64
    // in even case 1,1,2,2,3,3,4,4... works
    // in odd case, use 0, 9, 25 triple to reenter even
    // [1,8] even, [10, 24] not even
    // do 10, 26, (16 dist)
    // [11, 24] and [27, odd n - 1] even

    if (n % 2 != 0 && n < 27) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans(n);
    int fill = 1;
    if (n % 2 != 0) {
        ans[0] = ans[9] = ans[25] = fill++;
        ans[10] = ans[26] = fill++;
        fillRange(ans, 1, 8, fill);
        fillRange(ans, 11, 24, fill);
        fillRange(ans, 27, n - 1, fill);
    } else {
        fillRange(ans, 0, n - 1, fill);
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
