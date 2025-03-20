from typing import List, Dict, Optional


# @leet start
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if not head:
            return None

        node = head
        while node:
            copy = Node(node.val)
            copy.next = node.next
            node.next = copy
            node = copy.next

        node = head
        while node:
            copy = node.next
            if node.random:
                copy.random = node.random.next
            node = node.next.next

        node = head
        while node:
            copy = node.next
            node = copy.next
            if copy.next:
                copy.next = copy.next.next

        return head.next


# @leet end

