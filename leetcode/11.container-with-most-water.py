from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1

        best = 0
        leftMax = rightMax = 0
        while l < r:
            leftMax = max(leftMax, height[l])
            rightMax = max(rightMax, height[r])
            curr = min(leftMax, rightMax) * (r - l)
            best = max(best, curr)
            if leftMax < rightMax:
                l += 1
            elif leftMax > rightMax:
                r -= 1
            else:
                l += 1
                r -= 1

        return best


# @leet end
