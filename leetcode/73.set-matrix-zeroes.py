from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        left = 0 in [row[0] for row in matrix]
        top = 0 in matrix[0]
        n = len(matrix)
        m = len(matrix[0])
        for row in range(1, n):
            for col in range(1, m):
                if matrix[row][col] == 0:
                    matrix[0][col] = matrix[row][0] = 0

        for row in range(1, n):
            if matrix[row][0] == 0:
                for col in range(1, m):
                    matrix[row][col] = 0

        for col in range(1, m):
            if matrix[0][col] == 0:
                for row in range(1, n):
                    matrix[row][col] = 0

        if left:
            for row in range(n):
                matrix[row][0] = 0
        if top:
            for col in range(m):
                matrix[0][col] = 0


# @leet end

