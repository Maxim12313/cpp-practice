from typing import List, Dict
from collections import defaultdict


# @leet start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        buy = prices[0]
        for val in prices:
            profit = max(profit, val - buy)
            buy = min(buy, val)
        return profit


# @leet end
