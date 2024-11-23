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
    string s;
    cin >> n >> s;
    int half = n / 2;
    bool works = n % 2 != 0;
    for (int i = 0; i < half; i++)
        if (s[i] != '1')
            works = false;

    if (s[half] != '/')
        works = false;

    for (int i = half + 1; i < n; i++)
        if (s[i] != '2')
            works = false;

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
