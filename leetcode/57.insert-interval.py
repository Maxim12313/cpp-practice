from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect_left, bisect_right


# @leet start
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        pass

        res = []
        i = 0
        # behind
        while i < len(intervals) and intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i += 1

        if i < len(intervals) and intervals[i][0] <= newInterval[0]:
            left, right = intervals[i]
            newInterval[0] = min(left, newInterval[0])
            newInterval[1] = max(right, newInterval[1])
            i += 1

        while i < len(intervals) and intervals[i][0] <= newInterval[1]:
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1

        res.append(newInterval)
        while i < len(intervals):
            res.append(intervals[i])
            i += 1
        return res


# @leet end

