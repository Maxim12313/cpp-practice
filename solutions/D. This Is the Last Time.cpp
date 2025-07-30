#include <bits/stdc++.h>
using namespace std;

template <typename List>
string string_list(List &list) {
    string s = "[";
    for (auto x : list)
        s += to_string(x) + ", ";
    return s + ']';
}

struct Casino {
    int l;
    int r;
    int real;
    bool operator<(const Casino &o) const {
        return l < o.l;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<Casino> casinos(n);
    for (auto &c : casinos)
        cin >> c.l >> c.r >> c.real;

    sort(begin(casinos), end(casinos));
    int largest = k;
    for (auto [l, r, real] : casinos) {
        if (l <= largest && largest <= r) {
            largest = max(largest, real);
        }
    }
    cout << largest << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
