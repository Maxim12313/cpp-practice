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

// Problem: Problem C - Just for Sidekicks
// Contest: UMPT Segtree Praxis
// Judge: Kattis
// URL: https://open.kattis.com/contests/dgj4zg/problems/justforsidekicks
// Memory Limit: 1024
// Time Limit: 3000
// Start: Sat Feb  1 16:47:10 2025

using namespace std;
using ll = long long;
#define all(A) begin(A), end(A)

template <typename T> struct FenwickTree {
    vector<T> tree;

    FenwickTree() {}
    FenwickTree(int n) {
        tree.resize(n);
    }
    // O(n)
    FenwickTree(vector<T> &v) {
        init(v);
    }
    void init(vector<T> &v) {
        tree.assign(size(v), T(0));
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
    int n, q;
    cin >> n >> q;
    vector<int> V(6);
    for (int &val : V)
        cin >> val;

    string s;
    cin >> s;

    vector<FenwickTree<int>> bitFreqs(6);

    for (int i = 0; i < 6; i++) {
        vector<int> data(n, 0);
        for (int j = 0; j < n; j++)
            if (s[j] == i + '1')
                data[j] = 1;
        bitFreqs[i].init(data);
    }

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        switch (type) {
        case 1:
            a--;
            b--;
            for (int i = 0; i < 6; i++) {
                if (i + '1' == s[a])
                    bitFreqs[i].add(a, -1);
                if (i == b)
                    bitFreqs[i].add(a, 1);
            }
            s[a] = char(b + '1');
            break;
        case 2:
            a--;
            V[a] = b;
            break;
        case 3:
            a--;
            b--;
            ll sum = 0;
            for (int i = 0; i < 6; i++) {
                sum += ll(V[i]) * bitFreqs[i].sum(a, b);
            }
            cout << sum << '\n';
            break;
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
