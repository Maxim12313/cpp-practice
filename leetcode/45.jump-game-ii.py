from typing import List, Dict
from collections import defaultdict


# @leet start
class Solution:
    def jump(self, nums: List[int]) -> int:
        # greedy

        count = 0
        right = 0
        i = 0
        while right < len(nums) - 1:
            next = 0
            while i <= min(right, len(nums) - 1):
                next = max(next, i + nums[i])
                i += 1
            count += 1
            right = next
        return count


# @leet end
