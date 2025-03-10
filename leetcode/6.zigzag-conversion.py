from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        size = 2 * numRows - 2
        res = ""
        for r in range(numRows):
            for i in range(r, len(s), size):
                res += s[i]
                if 0 < r and r < numRows - 1:
                    offset = size - 2 * r
                    if i + offset < len(s):
                        res += s[i + offset]
        return res


# @leet end

