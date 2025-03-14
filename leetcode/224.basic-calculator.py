from typing import List, Dict


# @leet start
class Solution:
    def operate(self, op, a, b):
        match op:
            case "+":
                return a + b
            case "-":
                return a - b
            case "*":
                return a * b
            case "/":
                return a / b
        assert False

    def isnum(self, c):
        ops = "+-*/"
        return c not in ops and c not in "()"

    def calculate(self, s: str) -> int:
        tokens = s.split()
        ops = "+-*/"
        st = []
        curr = []
        for token in tokens:
            if token == "(":
                st.append(curr)
                curr = []


# @leet end
