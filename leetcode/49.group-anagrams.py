from typing import List, Dict, Tuple
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def getFreqs(self, s: str):
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord("a")] += 1
        return tuple(freq)

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        freqs = [self.getFreqs(word) for word in strs]
        added = [False] * len(strs)
        res = defaultdict(list)
        for i in range(len(strs)):
            res[freqs[i]].append(strs[i])
        return list(res.values())


# @leet end

