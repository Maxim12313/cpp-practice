#include "headers.hpp"

// @leet start
class Solution {
public:
    vector<string> split(string &s) {
        vector<string> res;
        string curr;
        for (char c : s) {
            if (isdigit(c)) {
                curr += c;
            } else {
                if (curr.size())
                    res.push_back(curr);
                curr = "";
            }

            if (!isdigit(c) && c != ' ') {
                res.push_back(string() + c);
            }
        }
        if (curr.size())
            res.push_back(curr);
        return res;
    }

    int operate(char op, int a, int b) {
        switch (op) {
        case '*':
            return a * b;
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '/':
            return a / b;
        }
        assert(false);
    }

    int calculate(string s) {
        vector<string> tokens = split(s);
        // for (string &sa : tokens)
        //     cout << sa << ",";
        // cout << "\n";

        vector<pair<int, char>> st;
        st.push_back({0, '+'});

        string ops = "*+-/";
        for (string &token : tokens) {
            if (token == "(") {
                st.push_back({0, '+'});
            } else if (token == ")") {
                int b = st.back().first;
                st.pop_back();
                auto [a, op] = st.back();
                st.back() = {operate(op, a, b), '?'};
            } else if (ops.contains(token)) {
                st.back().second = token[0];
            } else {
                int b = stoi(token);
                auto [a, op] = st.back();
                st.back() = {operate(op, a, b), '?'};
            }
        }

        return st[0].first;
    }
};
// @leet end
