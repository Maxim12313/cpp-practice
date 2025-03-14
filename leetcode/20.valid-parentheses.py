from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect_left, bisect_right


# @leet start
class Solution:
    def getIndex(self, c):
        if c in "()":
            return 0
        if c in "{}":
            return 1
        return 2

    def isBack(self, c):
        return c in "})]"

    def isValid(self, s: str) -> bool:
        balance = [0] * 3
        for c in s:
            i = self.getIndex(c)
            add = -1 if self.isBack(c) else 1
            balance[i] += add
            print(balance, add)
            if balance[i] < 0:
                return False

        for val in balance:
            print(val)
            if val != 0:
                return False
        return True


# @leet end

