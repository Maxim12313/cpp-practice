from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect_left, bisect_right


# @leet start
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0:
            return []

        ranges = [[nums[0], nums[0]]]
        for i in range(1, len(nums)):
            if nums[i] - 1 == ranges[-1][1]:
                ranges[-1][1] = nums[i]
            else:
                ranges.append([nums[i], nums[i]])

        res = []
        for p in ranges:
            if p[0] == p[1]:
                res.append(str(p[0]))
            else:
                res.append(f"{p[0]}->{p[1]}")
        return res


# @leet end

