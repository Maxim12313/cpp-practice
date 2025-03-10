from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet


# @leet start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        post = [0] * len(nums)
        post.append(1)

        for i in range(len(nums) - 1, -1, -1):
            post[i] = nums[i] * post[i + 1]

        prod = 1
        ans = [0] * len(nums)
        for i in range(len(nums)):
            ans[i] = prod * post[i + 1]
            prod *= nums[i]
        return ans


# @leet end
