from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def trap(self, height: List[int]) -> int:
        # if smaller, then count as obstacle area
        # if bigger, cashout with prev

        total = 0
        prevTall = 0
        obstacle = 0
        for i in range(1, len(height)):
            if height[prevTall] <= height[i]:
                total += height[prevTall] * (i - prevTall - 1)
                prevTall = i
                total -= obstacle
                obstacle = 0
            else:
                obstacle += height[i]

        stop = prevTall
        obstacle = 0
        prevTall = len(height) - 1
        for i in reversed(range(stop, len(height) - 1)):
            if height[prevTall] <= height[i]:
                total += height[prevTall] * (prevTall - i - 1)
                prevTall = i
                total -= obstacle
                obstacle = 0
            else:
                obstacle += height[i]

        return total


# @leet end

