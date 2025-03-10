from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def reverseWords(self, s: str) -> str:
        res = s.strip().split()
        res.reverse()
        return " ".join(res)


# @leet end

