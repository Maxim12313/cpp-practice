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
    int n, c;
    cin >> n >> c;
    vector<int> t(n);
    for (int &val : t)
        cin >> val;

    int count = 0;
    int prev = -c;
    for (int val : t) {
        if (val - prev >= c) {
            count++;
            prev = val;
        }
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
