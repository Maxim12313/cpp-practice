from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        charFreq = defaultdict(int)
        for c in magazine:
            charFreq[c] += 1

        for c in ransomNote:
            if charFreq[c] == 0:
                return False
            charFreq[c] -= 1
        return True


# @leet end

