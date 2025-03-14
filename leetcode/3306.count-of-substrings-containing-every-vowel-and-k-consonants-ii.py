from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    vowels = {"a", "e", "i", "o", "u"}

    def greaterEqK(self, word: str, k: int) -> int:
        vowelFreq = defaultdict(int)
        consonants = 0
        total = 0
        l = 0
        for r in range(len(word)):
            if word[r] in self.vowels:
                vowelFreq[word[r]] += 1
            else:
                consonants += 1

            while l <= r and len(vowelFreq) == len(self.vowels) and consonants >= k:
                total += len(word) - r
                if word[l] in self.vowels:
                    vowelFreq[word[l]] -= 1
                    if vowelFreq[word[l]] == 0:
                        vowelFreq.pop(word[l])
                else:
                    consonants -= 1

                l += 1

        return total

    def countOfSubstrings(self, word: str, k: int) -> int:
        return self.greaterEqK(word, k) - self.greaterEqK(word, k + 1)


# @leet end
