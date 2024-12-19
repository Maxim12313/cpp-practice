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

struct Customer {
    int l, r, id;
    bool operator<(const Customer &o) const {
        return l < o.l;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Customer> customers(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        customers[i] = {a, b, i};
    }
    sort(all(customers));

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq; // min pq

    vector<int> ordering(n);
    int count = 1;
    pq.push({0, count++});
    for (auto [l, r, id] : customers) {
        auto [time, room] = pq.top();
        if (time <= l) {
            pq.pop();
        } else {
            room = count++;
        }
        pq.push({r + 1, room});
        ordering[id] = room;
    }
    cout << count - 1 << "\n";
    for (int val : ordering)
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
