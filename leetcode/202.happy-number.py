from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect_left, bisect_right


# @leet start
class Solution:
    def getNext(self, n: int) -> int:
        curr = 0
        while n > 0:
            curr += (n % 10) ** 2
            n //= 10
        return curr

    def isHappy(self, n: int) -> bool:
        fast = slow = n
        while True:
            fast = self.getNext(self.getNext(fast))
            slow = self.getNext(slow)
            if fast == slow:
                break
        return fast == 1


# @leet end
