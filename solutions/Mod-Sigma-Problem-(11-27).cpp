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

// tree is 1 indexed, but operations work 0 indexed
template <typename T> struct FenwickTree {
    vector<T> tree;
    FenwickTree(int n) {
        tree.resize(n + 1);
    }
    FenwickTree(vector<int> &v) {
        tree.resize(size(v) + 1);
        for (int i = 0; i < size(v); i++)
            add(i, v[i]);
    }
    T sum(int k) {
        k++;
        T sum = T(0);
        while (k >= 1) {
            sum += tree[k];
            k -= k & -k;
        }
        return sum;
    }
    // [l, r]
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int k, T x) {
        k++;
        while (k < tree.size()) {
            tree[k] += x;
            k += k & -k;
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int64_t> e(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i];
        e[i] %= m;
    }

    for (int i = 1; i < n; i++)
        e[i] = (e[i] + e[i - 1]) % m;

    FenwickTree<int64_t> ft(m);
    int64_t ways = 0;
    int64_t leftWays = 0;
    for (int r = 0; r < n; r++) {
        int64_t add = ft.sum(e[r] + 1, m - 1) * m;
        int64_t res = e[r] * (r + 1) - leftWays + add;
        ways += res;
        leftWays += e[r];
        ft.add(e[r], 1);
    }
    cout << ways << "\n";
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
