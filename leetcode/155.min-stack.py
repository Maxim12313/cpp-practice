from typing import List, Dict
# from collections import defaultdict
# from sortedcontainers import SortedDict, SortedSet
# from bisect import bisect_left, bisect_right


# @leet start
class MinStack:
    numSt: List[int]
    minSt: List[int]

    def __init__(self):
        self.numSt = []
        self.minSt = []

    def push(self, val: int) -> None:
        self.numSt.append(val)
        nextMin = min(val, self.minSt[-1]) if len(self.minSt) else val
        self.minSt.append(nextMin)

    def pop(self) -> None:
        self.numSt.pop()
        self.minSt.pop()

    def top(self) -> int:
        return self.numSt[-1]

    def getMin(self) -> int:
        return self.minSt[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @leet end

