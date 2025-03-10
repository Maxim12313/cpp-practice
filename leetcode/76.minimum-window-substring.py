from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        needed = defaultdict(int)
        for c in t:
            needed[c] += 1

        minSize = len(s) + 1
        charFreq = defaultdict(int)
        count = 0
        minL = minR = -1
        l = 0
        for r in range(len(s)):
            if s[r] not in needed:
                continue

            charFreq[s[r]] += 1
            if charFreq[s[r]] == needed[s[r]]:
                count += 1

            while l <= r and count >= len(needed):
                if s[l] not in needed:
                    l += 1
                    continue

                if minSize > r - l + 1:
                    minSize = r - l + 1
                    minL, minR = l, r

                if s[l] in needed and charFreq[s[l]] == needed[s[l]]:
                    count -= 1
                charFreq[s[l]] -= 1
                l += 1

        return "" if minSize > len(s) else s[minL : minR + 1]


# @leet end
