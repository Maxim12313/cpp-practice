from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        target = strs[0]
        i = 0
        while i < len(target):
            works = True
            for word in strs:
                if i >= len(word) or word[i] != target[i]:
                    works = False
            if not works:
                break
            i += 1
        return target[:i]


# @leet end

