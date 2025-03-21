from typing import List, Dict, Optional


# @leet start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        while node:
            while node.next and node.next.val == node.val:
                node.next = node.next.next
            node = node.next
        return head


# @leet end

