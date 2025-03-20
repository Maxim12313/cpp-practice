from typing import List, Dict, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @leet start
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return None

        count = 0
        end = head
        while end and count < k:
            end = end.next
            count += 1

        if count < k:
            return head

        prev = None
        node = head
        while node != end:
            next = node.next
            node.next = prev
            prev = node
            node = next

        head.next = self.reverseKGroup(end, k)

        return prev


# @leet end
