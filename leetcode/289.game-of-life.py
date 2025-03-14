from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def countNeighbors(self, board: List[List[int]], r, c) -> int:
        n = len(board)
        m = len(board[0])
        count = 0
        for i in [-1, 0, 1]:
            for j in [-1, 0, 1]:
                if i == 0 and j == 0:
                    continue
                r2 = r + i
                c2 = c + j
                if r2 < 0 or r2 == n or c2 < 0 or c2 == m:
                    continue
                count += board[r2][c2] % 2
        return count

    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        # 0 = 0 -> 0
        # 1 = 1 -> 1
        # 2 = 0 -> 1
        # 3 = 1 -> 0
        # get prev with mod 2

        n = len(board)
        m = len(board[0])
        for row in range(n):
            for col in range(m):
                count = self.countNeighbors(board, row, col)
                isOne = (bool(board[row][col]) and count == 2) or count == 3
                if board[row][col] != int(isOne):
                    board[row][col] += 2

        for row in range(n):
            for col in range(m):
                val = board[row][col]
                board[row][col] = int(val == 2 or val == 1)


# @leet end

