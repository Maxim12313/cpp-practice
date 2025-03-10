from typing import List, Dict
from collections import defaultdict


# @leet start
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # will be half or more
        cand = nums[0]
        freq = 1
        for i in range(1, len(nums)):
            freq += 1 if cand == nums[i] else -1
            if freq == 0:
                cand = nums[i]
                freq = 1
        return cand


# @leet end

