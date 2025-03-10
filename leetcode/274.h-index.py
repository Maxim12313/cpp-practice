from typing import List, Dict
from collections import defaultdict


# @leet start
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)
        k = 0
        for h in range(len(citations), -1, -1):  # [len, 0]
            while k < len(citations) and citations[k] >= h:
                k += 1
            if k >= h:
                return h
        return -1


# @leet end

