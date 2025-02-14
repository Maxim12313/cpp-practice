#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
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

// Problem: Sliding Window Cost
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1077
// Memory Limit: 512
// Time Limit: 1000
// Start: Thu Feb 13 22:55:38 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

template <typename T> class RunMedian {
public:
    ll left = 0;
    ll right = 0;
    multiset<T, greater<T>> low; // non increasing
    multiset<T> high;            // non decreasing

    ll cost() {
        return right - left + (size() % 2 == 1 ? median() : 0);
    }

    size_t size() {
        return low.size() + high.size();
    }
    // assuming choose lower for even median
    T median() {
        assert(size() > 0);
        if (low.size() >= high.size())
            return *begin(low);
        return *begin(high);
    }
    // low has extra if odd
    void push(T val) {
        val = balance(val);
        if (low.size() <= high.size()) {
            left += val;
            low.insert(val);
        } else {
            right += val;
            high.insert(val);
        }
    }

    void erase(T val) {
        auto it1 = low.find(val);
        auto it2 = high.find(val);
        assert(it1 != end(low) || it2 != end(high));
        if (it1 != end(low)) {
            left -= *it1;
            low.erase(it1);
        } else {
            right -= *it2;
            high.erase(it2);
        }
        rebalance();
    }

private:
    // balance and return the value between lo and hi to insert
    T balance(T val) {
        if (!low.empty() && val < *begin(low)) {
            auto it = begin(low);
            T temp = *it;
            left -= *it;
            low.erase(it);
            left += val;
            low.insert(val);
            return temp;
        }
        if (!high.empty() && val > *begin(high)) {
            auto it = begin(high);
            T temp = *it;
            right -= *it;
            high.erase(it);
            right += val;
            high.insert(val);
            return temp;
        }
        return val;
    }
    void rebalance() {
        if (low.size() < high.size()) {
            auto it = begin(high);
            left += *it;
            low.insert(*it);
            right -= *it;
            high.erase(it);
        } else if (low.size() > high.size() + 1) {
            auto it = begin(low);
            right += *it;
            high.insert(*it);
            left -= *it;
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

    RunMedian<int> median;
    for (int i = 0; i < k; i++)
        median.push(A[i]);

    vector<ll> costs(n - k + 1);
    costs[0] = median.cost();

    for (int l = 0; l < size(costs) - 1; l++) {
        int r = l + k;
        median.erase(A[l]);
        median.push(A[r]);
        costs[l + 1] = median.cost();
    }
    for (ll val : costs)
        cout << val << " ";
    cout << '\n';
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
