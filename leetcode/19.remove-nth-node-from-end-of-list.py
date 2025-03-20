from typing import List, Dict, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @leet start
# Definition for singly-linked list.
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        root = ListNode(0, head)
        right = root
        for i in range(n + 1):  # can always go lenList+1 times
            right = right.next

        left = root
        while right:
            left = left.next
            right = right.next

        # sz >= 1, dummy + actual
        left.next = left.next.next
        return root.next


# @leet end

