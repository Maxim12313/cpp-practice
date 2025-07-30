#include <bits/stdc++.h>
using namespace std;

template <typename List>
string string_list(List &list) {
    string s = "[";
    for (auto x : list)
        s += to_string(x) + ", ";
    return s + ']';
}

void solve() {
    // at most can increase total value by k
    // issue is about whether losing to flipping
    uint64_t n, k;
    cin >> n >> k;
    vector<uint64_t> A(n);
    for (auto &val : A)
        cin >> val;

    for (int i = 0; i < 64; i++) {
        if (k == 0)
            break;

        uint64_t bit = 1ULL << i;
        for (auto &val : A) {
            if (val & bit)
                continue;

            if (k < bit) {
                k = 0;
                break;
            }
            val |= bit;
            k -= bit;
        }
    }

    int count = 0;
    for (uint64_t val : A) {
        for (int i = 0; i < 64; i++) {
            if (val & (1ULL << i)) {
                count++;
            }
        }
    }
    cout << count << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
