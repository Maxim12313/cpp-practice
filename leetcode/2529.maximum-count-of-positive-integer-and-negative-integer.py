from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect, bisect_left, bisect_right


# @leet start
class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        left = bisect_left(nums, 0)
        right = bisect_right(nums, 0)

        neg = left
        pos = len(nums) - right
        if left < len(nums) and nums[left] < 0:
            neg += 1

        return max(neg, pos)


# @leet end

