#include <algorithm>
#include <cassert>
#include <cfenv>
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

struct Range {
    int l, r;
    vector<int> idxs;
    bool operator<(const Range &other) const {
        if (l != other.l)
            return l < other.l;
        return r > other.r;
    }
};

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

void processDup(vector<Range> &ranges) {
    vector<Range> res;
    res.push_back(ranges[0]);
    for (int i = 1; i < size(ranges); i++) {
        auto &[l, r, idxs] = res.back();
        auto &[a, b, c] = ranges[i];
        if (l == a && r == b)
            idxs.push_back(c[0]);
        else
            res.push_back(ranges[i]);
    }
    swap(ranges, res);
}

// returns greatest val outside range
int compress(vector<Range> &ranges) {
    map<int, int> compress;
    for (auto &[l, r, idxs] : ranges) {
        compress[l];
        compress[r];
    }

    int time = 0;
    for (auto &[a, b] : compress)
        b = time++;

    for (auto &[l, r, idxs] : ranges) {
        l = compress[l];
        r = compress[r];
    }
    return time;
}

void solve() {
    int n;
    cin >> n;
    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r, {i}};
    }
    sort(begin(ranges), end(ranges));
    processDup(ranges);
    int time = compress(ranges);

    vector<int> contains(n), contained(n);
    FenwickTree<int> ft(time);
    for (int i = n - 1; i >= 0; i--) {
        auto &[l, r, idxs] = ranges[i];

        for (int j = 0; j < size(idxs); j++)
            ft.add(r, 1);

        for (int j : idxs)
            contains[j] = ft.sum(r) - 1;
    }

    ft = FenwickTree<int>(time);
    for (int i = 0; i < n; i++) {
        auto &[l, r, idxs] = ranges[i];

        for (int j = 0; j < size(idxs); j++)
            ft.add(r, 1);

        for (int j : idxs)
            contained[j] = ft.sum(r, time - 1) - 1;
    }

    for (int val : contains)
        cout << val << " ";
    cout << "\n";
    for (int val : contained)
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
