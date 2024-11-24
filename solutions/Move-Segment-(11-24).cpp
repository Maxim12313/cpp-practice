#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
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
    string s;
    cin >> s;
    int i = 0;

    string left;
    while (i < n && k > 1) {
        if (s[i] == '1') {

            while (i < n && s[i] == '1')
                left += s[i++];

            k--;
        } else {
            left += s[i++];
        }
    }

    string m1;
    while (i < n && s[i] == '0')
        m1 += s[i++];

    string m2;
    while (i < n && s[i] == '1')
        m2 += s[i++];

    string right;
    while (i < n)
        right += s[i++];

    string res = left + m2 + m1 + right;
    cout << res << "\n";
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
