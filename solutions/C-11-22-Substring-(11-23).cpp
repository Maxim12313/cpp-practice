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
    // expand from every /
    int n;
    string s;
    cin >> n >> s;
    n = s.size();
    int count1 = 0;
    int count2 = 0;
    bool seenMiddle = false;
    int maxSize = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '2' && seenMiddle) {
            count1 = count2 = 0;
            seenMiddle = false;
        }

        if (s[i] == '/')
            seenMiddle = true;
        if (s[i] == '1' && !seenMiddle)
            count1++;

        if (s[i] == '2' && seenMiddle)
            count2++;
        if (s[i] == '2' && !seenMiddle)
            count1 = 0;

        if (seenMiddle)
            maxSize = max(maxSize, 1 + 2 * min(count1, count2));
    }
    cout << maxSize << "\n";
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
