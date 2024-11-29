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

// a to b with c obstacle
int moves(int n, int a, int b, int c) {
    if (a > b)
        swap(a, b);
    if (b < c || a > c)
        return b - a;
    return a + n - b;
}

void solve() {
    int n, q;
    cin >> n >> q;
    int l = 1;
    int r = 2;
    int total = 0;
    while (q--) {
        char h;
        int t;
        cin >> h >> t;
        // exactly 1 way that works
        int add;
        if (h == 'L') {
            add = moves(n, l, t, r);
            l = t;
        } else {
            add = moves(n, r, t, l);
            r = t;
        }
        total += add;
    }
    cout << total << "\n";
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
