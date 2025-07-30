#include <bits/stdc++.h>
using namespace std;

template <typename List>
string string_list(List &list) {
    string s = "[";
    for (auto x : list)
        s += to_string(x) + ", ";
    return s + ']';
}

bool works(vector<int> &A, int n) {
    // x, y
    // a = x + ny
    // b = 2x + (n - 1)y
    // a - b = -x + y
    // x = y - a + b

    // a - ny = y - a + b
    // 2a - b =  (n + 1)y
    // y = (2a - b) / (n + 1)
    // x = y - a + b

    int a = A[1];
    int b = A[2];

    int y = (2 * a - b) / (n + 1);
    int x = y - a + b;

    if (x < 0 || y < 0) {
        return false;
    }

    for (int i = 1; i <= n; i++) {
        A[i] -= i * x;
        A[i] -= (n - i + 1) * y;
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] != 0)
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    // i + (n - i + 1) = n + 1
    bool ans = works(A, n);
    cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
