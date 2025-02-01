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

// Problem: Problem B - Supercomputer
// Contest: UMPT Segtree Praxis
// Judge: Kattis
// URL: https://open.kattis.com/contests/dgj4zg/problems/supercomputer
// Memory Limit: 1024
// Time Limit: 4000
// Start: Sat Feb  1 16:47:10 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

template <typename T> struct FenwickTree {
    vector<T> tree;
    FenwickTree(int n) {
        tree.resize(n, T(0));
    }

    // O(n)
    FenwickTree(vector<T> &v) {
        tree.resize(size(v), T(0));
        for (int i = 0; i < size(v); i++) {
            tree[i] += v[i];
            int next = i | (i + 1);
            if (next < size(v))
                tree[next] += tree[i];
        }
    }

    // if k < 0, ret 0 still
    T sum(int k) {
        T sum = T(0);
        while (k >= 0) {
            sum += tree[k];
            k = (k & (k + 1)) - 1;
        }
        return sum;
    }
    // [l, r]
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int k, T change) {
        while (k < size(tree)) {
            tree[k] += change;
            k = k | (k + 1);
        }
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    FenwickTree<int> bit(n);
    vector<int> data(n, 0);
    while (k--) {
        char type;
        int a;
        cin >> type >> a;
        a--;
        if (type == 'F') {
            int change = 1 - 2 * data[a];
            data[a] += change;
            bit.add(a, change);
        } else {
            int b;
            cin >> b;
            b--;
            cout << bit.sum(a, b) << "\n";
        }
    }
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
