from typing import List, Dict
from collections import defaultdict
from sortedcontainers import SortedDict, SortedSet
from bisect import bisect_left, bisect_right


# @leet start
class LRUCache:
    class Node:
        key = None
        val = None
        prev = None
        next = None

    mp: Dict[int, Node] = None
    capacity: int = None
    tail: Node = None
    head: Node = None

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.mp = dict()

    def get(self, key: int) -> int:
        if key not in self.mp:
            return -1

        curr = self.mp[key]
        self.delete(key)
        self.addLast(key, curr.val)
        return curr.val

    def put(self, key: int, value: int) -> None:
        self.delete(key)
        self.addLast(key, value)

        if len(self.mp) > self.capacity:
            self.delete(self.tail.key)

    def addLast(self, key: int, value: int):
        curr = self.Node()
        curr.val = value
        curr.key = key
        if not self.head:
            self.head = self.tail = curr
        else:
            prev = self.head
            prev.next = curr
            curr.prev = prev
            self.head = curr

        self.mp[key] = curr

    def delete(self, key) -> None:
        if key not in self.mp:
            return

        curr = self.mp[key]
        prev = curr.prev
        if prev:
            prev.next = curr.next
        else:
            self.tail = curr.next

        if curr.next:
            curr.next.prev = prev
        else:
            self.head = prev

        self.mp.pop(key)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# @leet end
