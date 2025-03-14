from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split()
        if len(s) != len(pattern):
            return False
        toWord = defaultdict(str)
        toChar = defaultdict(str)
        for c, word in zip(pattern, s):
            if c in toWord and toWord[c] != word:
                return False
            if word in toChar and toChar[word] != c:
                return False
            toWord[c] = word
            toChar[word] = c
        return True


# @leet end

