from typing import List, Dict
from collections import defaultdict
from sortedcontainers import sortedset
import random


# @leet start
class RandomizedSet:
    idxs = None
    vals = None

    def __init__(self):
        self.idxs = dict()
        self.vals = []

    def insert(self, val: int) -> bool:
        existed = val in self.idxs

        if not existed:
            self.idxs[val] = len(self.vals)
            self.vals.append(val)

        return not existed

    def remove(self, val: int) -> bool:
        existed = val in self.idxs

        if existed:
            last = self.vals[-1]
            lastIdx = self.idxs[last]

            # set swap to last
            self.vals[self.idxs[val]] = last
            self.idxs[last] = self.idxs[val]

            # pop from last
            self.vals.pop()
            self.idxs.pop(val)

        return existed

    def getRandom(self) -> int:
        return random.choice(self.vals)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
# @leet end
