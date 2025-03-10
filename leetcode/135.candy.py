from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def candy(self, ratings: List[int]) -> int:
        total = len(ratings)
        i = 1
        while i < len(ratings):
            if ratings[i - 1] == ratings[i]:
                i += 1
                continue

            hi = 0
            while i < len(ratings) and ratings[i - 1] < ratings[i]:
                hi += 1
                total += hi
                i += 1

            # counting descending stair backwards to valley
            lo = 0
            while i < len(ratings) and ratings[i - 1] > ratings[i]:
                lo += 1
                total += lo
                i += 1

            # double counted last tallest i
            # replaced with larger after sub smaller
            total -= min(lo, hi)

        return total


# @leet end

