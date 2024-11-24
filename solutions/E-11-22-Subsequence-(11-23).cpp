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

int lb(vector<int> &v, int val) {
    return lower_bound(begin(v), end(v), val) - begin(v);
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> idx1, idx2, idxm;
    for (int i = 0; i < size(s); i++) {
        if (s[i] == '1')
            idx1.push_back(i);
        else if (s[i] == '2')
            idx2.push_back(i);
        else
            idxm.push_back(i);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        auto works = [&](int length) -> bool {
            if (length == 0) {
                int j = lb(idxm, l);
                if (j >= size(idxm))
                    return false;
                return idxm[j] <= r;
            }

            int i = lb(idx1, l);
            if (i + length - 1 >= size(idx1))
                return false;

            int j = lb(idxm, idx1[i + length - 1]);
            if (j >= size(idxm))
                return false;

            int k = lb(idx2, idxm[j]);
            if (k + length - 1 >= size(idx2))
                return false;

            return idx2[k + length - 1] <= r;
        };

        int lo = -1;
        int hi = r - l + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (works(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        cout << (lo == -1 ? 0 : 2 * lo + 1) << "\n";
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
