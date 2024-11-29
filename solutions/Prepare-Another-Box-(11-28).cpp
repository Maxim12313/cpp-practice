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

void solve() {
    int n;
    cin >> n;
    vector<int> toy(n);
    for (int &val : toy)
        cin >> val;
    vector<int> box(n - 1);
    for (int &val : box)
        cin >> val;

    sort(begin(toy), end(toy));
    sort(begin(box), end(box));

    int j = n - 2;
    while (j >= 0 && toy[j + 1] <= box[j]) {
        j--;
    }
    int minSize = toy[j + 1];
    while (j >= 0 && toy[j] <= box[j])
        j--;
    cout << (j < 0 ? minSize : -1) << "\n";
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
