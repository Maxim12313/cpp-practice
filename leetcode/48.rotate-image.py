from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def rotatePoint(self, matrix: List[List[int]], r, c):
        n = len(matrix)
        # (r, c) -> (c, n - r) -> (n - r, n - c) -> (n - c, r)
        points = [
            (r, c),
            (c, n - r - 1),
            (n - r - 1, n - c - 1),
            (n - c - 1, r),
        ]
        temp = matrix[n - c - 1][r]
        i = len(points) - 1
        while i >= 0:
            r1, c1 = points[i]
            r2, c2 = points[i - 1]
            matrix[r1][c1] = matrix[r2][c2]
            i -= 1

        matrix[r][c] = temp

    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        right = n - 1
        for row in range(n):
            for col in range(row, right):
                self.rotatePoint(matrix, row, col)
            right -= 1


# @leet end
