#include "headers.hpp"

// @leet start
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));
        map<int, vector<int>> groups;
        int i = n - 1;
        while (i >= 0) {
            vector<int> smaller{sorted[i]};
            while (i - 1 >= 0 && sorted[i] - sorted[i - 1] <= limit) {
                smaller.push_back(sorted[i - 1]);
                i--;
            }
            groups[smaller[0]] = smaller;
            i--;
        }

        // for (auto [a, b] : groups) {
        //     cout << a << '\n';
        //     for (int val : b)
        //         cout << val << " ";
        //     cout << "\n\n";
        // }

        for (int i = 0; i < n; i++) {
            int key = groups.lower_bound(nums[i])->first;
            nums[i] = groups[key].back();
            groups[key].pop_back();
            if (groups[key].empty())
                groups.erase(key);
        }
        return nums;
    }
};
// @leet end
