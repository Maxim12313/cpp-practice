#include "headers.hpp"

// @leet start
class Solution {
public:
    struct Trie {
        char val;
        vector<Trie *> next;
        Trie(char val) : val(val), next(26, nullptr) {
        }
    };

    Trie *build(vector<string> &words) {
        Trie *root = new Trie('-');
        for (string &s : words) {
            Trie *node = root;
            for (char c : s) {
                int idx = c - 'a';
                if (!node->next[idx])
                    node->next[idx] = new Trie(c);
                node = node->next[idx];
            }
        }
        return root;
    }

    int minValidStrings(vector<string> &words, string target) {
        // always worth continuing while exists way through
        int curr = 0;
        Trie *root = build(words);
        int count = 0;
        while (curr < target.size() && root->next[target[curr] - 'a']) {
            Trie *node = root;
            while (curr < target.size() && node->next[target[curr] - 'a']) {
                node = node->next[target[curr] - 'a'];
                curr++;
            }
            count++;
        }
        // this is wrong
        return curr >= target.size() ? count : -1;
    }
};
// @leet end
