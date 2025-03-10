from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        charFreq = defaultdict(int)
        l = 0
        for r in range(len(s)):
            charFreq[s[r]] += 1
            while l < r and charFreq[s[r]] > 1:
                charFreq[s[l]] -= 1
                l += 1
            longest = max(longest, r - l + 1)
        return longest


# @leet end

