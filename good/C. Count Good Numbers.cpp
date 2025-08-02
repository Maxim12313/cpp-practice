#include <bits/stdc++.h>
using namespace std;

template <typename List>
string string_list(List &list) {
    string s = "[";
    for (auto x : list)
        s += to_string(x) + ", ";
    return s + ']';
}

constexpr array<int, 4> primes = {2, 3, 5, 7};

// 2^4 = 16
int64_t r_count(int64_t n, int idx, int div, int count) {
    if (idx == primes.size()) {
        if (count == 0)
            return 0;
        int64_t amount = n / div;
        return count % 2 == 1 ? amount : -amount;
    }
    auto take = r_count(n, idx + 1, div * primes[idx], count + 1);
    auto leave = r_count(n, idx + 1, div, count);
    return take + leave;
}

// [1, n]
int64_t divides_incl(int64_t n) {
    return r_count(n, /*idx=*/0, /*div=*/1, /*count=*/0);
}

void solve() {
    int64_t l, r;
    cin >> l >> r;
    auto between = divides_incl(r) - divides_incl(l - 1);
    int64_t ans = (r - l + 1) - between;
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
