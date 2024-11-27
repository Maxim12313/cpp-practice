#include <algorithm>
#include <cassert>
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

int countWays(vector<string> &grid, int i, int j, int k) {
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || j < 0 || i == n || j == m)
        return 0;
    if (grid[i][j] == '#')
        return 0;
    if (k == 0)
        return 1;

    int count = 0;
    grid[i][j] = '#';
    count += countWays(grid, i - 1, j, k - 1);
    count += countWays(grid, i + 1, j, k - 1);
    count += countWays(grid, i, j - 1, k - 1);
    count += countWays(grid, i, j + 1, k - 1);
    grid[i][j] = '.';
    return count;
}

void solve() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> grid(h);
    for (string &s : grid)
        cin >> s;

    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            count += countWays(grid, i, j, k);
        }
    }
    cout << count << "\n";
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
