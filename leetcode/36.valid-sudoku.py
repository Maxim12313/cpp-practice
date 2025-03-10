from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def goodHorVer(self, board: List[List[str]]) -> bool:
        for r in range(9):
            hor = set()
            ver = set()
            for c in range(9):
                if board[r][c] != ".":
                    if board[r][c] in hor:
                        return False
                    hor.add(board[r][c])

                if board[c][r] != ".":
                    if board[c][r] in ver:
                        return False
                    ver.add(board[c][r])
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        if not self.goodHorVer(board):
            return False
        for i in range(3):
            for j in range(3):
                has = set()
                for r in range(3):
                    for c in range(3):
                        val = board[3 * i + r][3 * j + c]
                        if val == ".":
                            continue
                        if val in has:
                            return False
                        has.add(val)
        return True


# @leet end

