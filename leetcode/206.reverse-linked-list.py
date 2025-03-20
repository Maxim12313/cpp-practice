from typing import List, Dict, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @leet start


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None

        prev = head
        node = head.next
        prev.next = None
        while node:
            next = node.next
            node.next = prev
            prev = node
            node = next

        return prev


# @leet end

