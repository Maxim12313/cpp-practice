from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect_left, bisect_right


# @leet start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda p: p[0])
        res = [intervals[0]]
        for i in range(1, len(intervals)):
            left, right = intervals[i]
            if res[-1][1] >= left:
                res[-1][1] = max(res[-1][1], right)
            else:
                res.append([left, right])

        return res


# @leet end

