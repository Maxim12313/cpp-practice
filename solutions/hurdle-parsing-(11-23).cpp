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
    vector<int> ans;
    int count = 0;
    for (int i = 1; i < size(s); i++) {
        if (s[i] == '|') {
            ans.push_back(count);
            count = 0;
        } else {
            count++;
        }
    }
    for (int val : ans)
        cout << val << " ";
    cout << "\n";
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
