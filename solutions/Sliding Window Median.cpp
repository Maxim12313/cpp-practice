#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// Problem: Sliding Window Median
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1076
// Memory Limit: 512
// Time Limit: 1000
// Start: Sat Feb  8 13:53:36 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

template <typename T> class RunMedian {
public:
    multiset<T, greater<T>> low; // non increasing
    multiset<T> high;            // non decreasing

    // assuming choose lower for even median
    T median() {
        assert(size(low) + size(high) > 0);
        if (size(low) >= size(high))
            return *begin(low);
        return *begin(high);
    }

    // low has extra if odd
    void push(T val) {
        val = balance(val);
        if (size(low) <= size(high))
            low.insert(val);
        else
            high.insert(val);
    }

    void erase(T val) {
        auto it1 = low.find(val);
        auto it2 = high.find(val);
        assert(it1 != end(low) || it2 != end(high));
        if (it1 != end(low))
            low.erase(it1);
        else
            high.erase(it2);
        rebalance();
    }

private:
    // balance and return the value between lo and hi to insert
    T balance(T val) {
        if (!low.empty() && val < *begin(low)) {
            auto it = begin(low);
            T temp = *it;
            low.erase(it);
            low.insert(val);
            return temp;
        }
        if (!high.empty() && val > *begin(high)) {
            auto it = begin(high);
            T temp = *it;
            high.erase(it);
            high.insert(val);
            return temp;
        }
        return val;
    }

    // rebalance after erase
    void rebalance() {
        if (size(low) < size(high)) {
            auto it = begin(high);
            low.insert(*it);
            high.erase(it);
        } else if (size(low) > size(high) + 1) {
            auto it = begin(low);
            high.insert(*it);
            low.erase(it);
        }
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &val : A)
        cin >> val;

    RunMedian<int> med;
    for (int i = 0; i < k - 1; i++)
        med.push(A[i]);

    vector<int> ans(n - k + 1);
    for (int l = 0; l < size(ans); l++) {
        int r = l + k - 1;
        med.push(A[r]);
        ans[l] = med.median();
        // med.print();
        // cout << "got " << ans[l] << "\n";
        // cout << "\n";
        med.erase(A[l]);
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
