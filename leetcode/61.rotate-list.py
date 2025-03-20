from typing import List, Dict, Optional


# @leet start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        node = head
        length = 0
        while node:
            length += 1
            node = node.next

        k %= length
        if k == 0:
            return head

        root = ListNode(0, head)
        left = root
        for i in range(length - k):  # before
            left = left.next

        right = left
        while right.next:
            right = right.next

        start = left.next
        left.next = None
        right.next = root.next
        root.next = start
        return root.next


# @leet end

