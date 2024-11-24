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
    cin >> n;
    // make all same
    vector<int> h(n);
    for (int &val : h)
        cin >> val;

    int maxFreq = 0;
    unordered_map<int, int> numFreq;
    for (int val : h) {
        numFreq[val]++;
        maxFreq = max(maxFreq, numFreq[val]);
    }
    cout << n - maxFreq << "\n";
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
