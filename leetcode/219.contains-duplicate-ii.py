from typing import List, Dict
from collections import defaultdict, Counter
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect_left, bisect_right


# @leet start
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        k = min(k + 1, len(nums))
        seen: set[int] = set()
        for i in range(k):
            if nums[i] in seen:
                return True
            seen.add(nums[i])

        for i in range(k, len(nums)):
            seen.remove(nums[i - k])
            if nums[i] in seen:
                return True
            seen.add(nums[i])
        return False


# @leet end
