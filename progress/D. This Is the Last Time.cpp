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
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
