from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = "".join(s.split())
        s = [c.lower() for c in s if c.isalnum()]
        for i in range(len(s) // 2):
            if s[i] != s[len(s) - 1 - i]:
                return False
        return True


# @leet end

