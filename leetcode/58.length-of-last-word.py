from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        word = s.strip().split()[-1]
        return len(word)


# @leet end
