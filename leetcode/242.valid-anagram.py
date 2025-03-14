from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq1 = defaultdict(int)
        for c in s:
            freq1[c] += 1

        freq2 = defaultdict(int)
        for c in t:
            freq2[c] += 1

        return freq1 == freq2


# @leet end

