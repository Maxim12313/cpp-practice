#include <algorithm>
#include <cassert>
#include <cfenv>
#include <climits>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
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

#define all(v) begin(v), end(v)

template <typename A, typename B> string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A> string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename T> class SegmentTree {
public:
    int n;
    vector<T> tree;
    T init = T(0); // initial value
    function<T(T, T)> combine = [](T a, T b) { return max(a, b); };

    SegmentTree(vector<T> &nums, T init, function<T(T, T)> combine)
        : n(int(size(nums))), init(init), combine(combine) {
        tree.resize(4 * n, init);
        build(nums, 0, n - 1, 0);
    }

    SegmentTree(vector<T> &nums, function<T(T, T)> combine)
        : n(int(size(nums))), combine(combine) {
        tree.resize(4 * n, init);
        build(nums, 0, n - 1, 0);
    }

    SegmentTree(vector<T> &nums) : n(size(nums)) {
        tree.resize(4 * n, init);
        build(nums, 0, n - 1, 0);
    }

    T query(int l, int r) {
        return query(0, n - 1, 0, l, r);
    }

    void update(int idx, T val) {
        update(0, n - 1, 0, idx, val);
    }

private:
    void build(vector<T> &nums, int l, int r, int k) {
        if (l == r) {
            tree[k] = nums[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(nums, l, m, 2 * k + 1);
        build(nums, m + 1, r, 2 * k + 2);
        tree[k] = combine(tree[2 * k + 1], tree[2 * k + 2]);
    }

    T query(int l, int r, int k, int outerL, int outerR) {
        if (r < outerL || outerR < l)
            return init;

        if (outerL <= l && r <= outerR)
            return tree[k];

        int m = l + (r - l) / 2;
        return combine(query(l, m, 2 * k + 1, outerL, outerR),
                       query(m + 1, r, 2 * k + 2, outerL, outerR));
    }

    void update(int l, int r, int k, int idx, T val) {
        if (l == r) {
            tree[k] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m)
            update(l, m, 2 * k + 1, idx, val);
        else
            update(m + 1, r, 2 * k + 2, idx, val);

        tree[k] = combine(tree[2 * k + 1], tree[2 * k + 2]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int &val : arr)
        cin >> val;

    if (arr.size() == 1)
        arr.push_back(arr[0]);

    for (int i = 0; i + 1 < n; i++)
        arr[i] = abs(arr[i] - arr[i + 1]);
    arr.pop_back();

    auto f1 = [](int a, int b) { return gcd(a, b); };
    SegmentTree<int> gcdTree(arr, f1);

    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r -= 2;
        ans[i] = l > r ? 0 : gcdTree.query(l, r);
    }

    for (int val : ans)
        cout << val << " ";
    cout << "\n";
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
