from typing import List, Dict
from collections import defaultdict


# @leet start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        right = 0

        i = 0
        while i < min(right + 1, len(nums)):
            right = max(right, i + nums[i])
            i += 1

        return right >= len(nums) - 1


# @leet end
