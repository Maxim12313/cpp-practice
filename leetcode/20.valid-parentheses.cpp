#include "headers.hpp"

// @leet start
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> toClose = {
            {'(', ')'}, {'[', ']'}, {'{', '}'}};

        stack<char> st;
        for (char c : s) {
            if (!toClose.count(c)) { // is closing
                if (st.empty() || c != toClose[st.top()])
                    return false;
                st.pop();
            } else { // is opening
                st.push(c);
            }
        }
        return st.empty();
    }
};
// @leet end
