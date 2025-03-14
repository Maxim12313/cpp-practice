from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect_left, bisect_right


# @leet start
class Solution:
    def simplifyPath(self, path: str) -> str:
        names = path.split("/")
        names = [name for name in names if len(name)]
        st = []
        for name in names:
            if name == "..":
                if len(st):
                    st.pop()
            elif name != ".":
                st.append(name)
        return "/" + "/".join(st)


# @leet end
