from typing import List, Dict


# @leet start
class Solution:
    def operate(self, operation: str, a, b):
        match operation:
            case "+":
                return a + b
            case "-":
                return a - b
            case "*":
                return a * b
            case "/":
                return int(a / b)
        print(operation, a, b)
        assert False

    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        operations = "+-*/"
        for token in tokens:
            if token in operations:
                res = self.operate(token, st[-2], st[-1])
                st.pop()
                st[-1] = res
            else:
                st.append(int(token))
        return st[0]


# @leet end

