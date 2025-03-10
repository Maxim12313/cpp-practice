from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        i = 0
        while i < len(words):
            line = []
            length = 0
            while i < len(words) and length + len(line) + len(words[i]) <= maxWidth:
                line.append(words[i])
                length += len(words[i])
                i += 1

            if len(line) == 1 or i == len(words):
                add = " ".join(line)
                add += " " * (maxWidth - len(add))
                res.append(add)
                continue

            spaceLength = maxWidth - length
            spaceCount = len(line) - 1
            spacePer = spaceLength // spaceCount
            spaceStr = " " * spacePer
            extra = spaceLength % spaceCount

            left = (spaceStr + " ").join(line[: extra + 1])
            right = spaceStr.join(line[extra + 1 :])
            add = left + spaceStr + right
            res.append(add)

            # print(spaceLength, spaceCount, spacePer, extra)
            # print(left, "|", right)
            # print()

        return res

        pass


# @leet end
