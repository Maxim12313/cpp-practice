from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        w = len(matrix[0])
        h = len(matrix)
        r = 0
        c = -1
        ans = []
        while w > 0 or h > 0:  # or
            for i in range(w):
                c += 1
                ans.append(matrix[r][c])
            h -= 1
            if h == 0:
                break

            for i in range(h):
                r += 1
                ans.append(matrix[r][c])
            w -= 1
            if w == 0:
                break

            for i in range(w):
                c -= 1
                ans.append(matrix[r][c])
            h -= 1
            if h == 0:
                break

            for i in range(h):
                r -= 1
                ans.append(matrix[r][c])
            w -= 1
            if w == 0:
                break
        return ans


# @leet end

