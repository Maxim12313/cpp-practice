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
    string s;
    cin >> s;
    vector<int> charIdx(26, 0);
    for (int i = 0; i < size(s); i++)
        charIdx[s[i] - 'A'] = i;

    int count = 0;
    for (int val = 1; val < 26; val++)
        count += abs(charIdx[val] - charIdx[val - 1]);
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
