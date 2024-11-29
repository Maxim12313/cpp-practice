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
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &val : A)
        cin >> val;
    vector<int> B(n);
    for (int &val : B)
        cin >> val;
    int a = *max_element(begin(A), end(A));
    int b = *max_element(begin(B), end(B));
    cout << a + b << "\n";
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
