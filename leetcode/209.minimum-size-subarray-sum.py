from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        minLength = len(nums) + 1
        l = 0
        sum = 0
        for r in range(len(nums)):
            sum += nums[r]
            while l <= r and sum >= target:
                minLength = min(minLength, r - l + 1)
                sum -= nums[l]
                l += 1

        return minLength if minLength <= len(nums) else 0


# @leet end

