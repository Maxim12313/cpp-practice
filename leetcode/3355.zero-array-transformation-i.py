from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        diff = [nums[0]] + [nums[i] - nums[i - 1] for i in range(1, len(nums))]
        curr = 0
        for l, r in queries:
            diff[l] -= 1
            if r + 1 < len(nums):
                diff[r + 1] += 1

        curr = 0
        for val in diff:
            curr += val
            if curr > 0:
                return False
        return True

        # 1 1 2 1 1 0

        # 1 2 3 4 5 6
        # 1 2 4 5 6 6


# @leet end
