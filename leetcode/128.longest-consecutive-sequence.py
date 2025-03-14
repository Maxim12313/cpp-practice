from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect_left, bisect_right


# @leet start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        longest = 0
        for val in nums:
            if val - 1 in nums:
                continue
            curr = 0
            while val in nums:
                curr += 1
                val += 1
            longest = max(longest, curr)
        return longest


# @leet end

