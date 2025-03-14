from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        diffs = [nums[0]] + [nums[i] - nums[i - 1] for i in range(1, len(nums))]

        curr = 0
        k = 0
        i = 0
        while i < len(nums):
            curr += diffs[i]
            while k < len(queries) and curr > 0:
                l, r, val = queries[k]
                k += 1
                diffs[l] -= val
                if r + 1 < len(nums):
                    diffs[r + 1] += val
                if l <= i and i <= r:
                    curr -= val

            if curr > 0:
                break
            i += 1

        return k if i == len(nums) or -1


# @leet end

