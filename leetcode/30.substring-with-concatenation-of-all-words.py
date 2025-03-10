from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def solveMod(
        self, mod: int, s: str, neededFreq: Dict[str, int], length: int
    ) -> List[int]:
        count = 0
        ans = []
        wordFreq = defaultdict(int)
        l = mod
        for r in range(mod, len(s) - length + 1, length):
            curr = s[r : r + length]

            # need to restart entirely
            if curr not in neededFreq:
                count = 0
                l = r + length
                wordFreq.clear()
                continue

            wordFreq[curr] += 1
            if wordFreq[curr] == neededFreq[curr]:
                count += 1
            elif wordFreq[curr] == neededFreq[curr] + 1:
                count -= 1

            # has potential
            while l <= r and wordFreq[curr] > neededFreq[curr]:
                prev = s[l : l + length]
                wordFreq[prev] -= 1
                if wordFreq[prev] == neededFreq[prev]:
                    count += 1
                elif wordFreq[prev] == neededFreq[prev]:
                    count -= 1
                l += length

            # satisfies
            if count == len(neededFreq):
                ans.append(l)
        return ans

    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        # convert into dict representing each word
        # try on all mod len and sliding window

        neededFreq = defaultdict(int)
        for word in words:
            neededFreq[word] += 1

        length = len(words[0])
        ans = []
        for i in range(length):
            ans += self.solveMod(i, s, neededFreq, length)
        return ans


# @leet end
