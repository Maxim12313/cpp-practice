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
    int64_t a, b, k;
    cin >> a >> b >> k;
    int64_t g = __gcd(a, b);
    int64_t dx = a / g;
    int64_t dy = b / g;
    bool works = dx <= k && dy <= k;
    cout << (works ? 1 : 2) << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
