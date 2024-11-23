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
    string s;
    cin >> s;
    int n = s.size();
    bool works = n % 2 == 0;
    vector<bool> has(26, false);
    for (int i = 1; i < n; i += 2) {
        if (s[i - 1] != s[i])
            works = false;
        if (has[s[i] - 'a'])
            works = false;
        has[s[i] - 'a'] = true;
    }
    cout << (works ? "Yes" : "No") << "\n";
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
