from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def romanToInt(self, s: str) -> int:
        convert = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        total = 0
        for i in range(1, len(s)):
            a = convert[s[i - 1]]
            b = convert[s[i]]
            if a < b:
                total -= a
            else:
                total += a
        return total + convert[s[-1]]


# @leet end

