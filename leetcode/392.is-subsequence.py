from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        for c in t:
            if i >= len(s):
                break
            if s[i] == c:
                i += 1
        return i >= len(s)


# @leet end
