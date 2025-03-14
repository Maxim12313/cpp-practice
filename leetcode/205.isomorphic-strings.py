from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        toT = defaultdict(str)
        mapped = set()
        for sc, tc in zip(s, t):
            if sc in toT and toT[sc] != tc:
                return False
            if sc not in toT and tc in mapped:
                return False
            toT[sc] = tc
            mapped.add(tc)
        return True


# @leet end

