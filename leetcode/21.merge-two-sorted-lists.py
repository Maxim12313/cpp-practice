from typing import List, Dict, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @leet start
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        root = ListNode()
        prev = root
        while list1 and list2:
            val = None
            if list1.val < list2.val:
                val = list1.val
                list1 = list1.next
            else:
                val = list2.val
                list2 = list2.next
            curr = ListNode(val)
            prev.next = curr
            prev = prev.next

        prev.next = list1 if list1 else list2

        return root.next


# @leet end

