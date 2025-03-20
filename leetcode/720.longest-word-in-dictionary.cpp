#include "headers.hpp"

// @leet start
class Solution {
public:
    struct Trie {
        char nextMove;
        char val;
        bool isWord = false;
        vector<Trie *> next = vector<Trie *>(26, nullptr);
        Trie(char val) : val(val) {}
    };

    Trie *build(vector<string> &words) {
        Trie *root = new Trie('#');
        for (string &word : words) {
            Trie *node = root;
            for (char c : word) {
                if (!node->next[c - 'a'])
                    node->next[c - 'a'] = new Trie(c);
                node = node->next[c - 'a'];
            }
            node->isWord = true;
        }
        return root;
    }

    int getLongest(Trie *curr) {
        if (!curr || !curr->isWord)
            return 0;

        int nextMove = -1;
        int longest = 0;
        for (int i = 0; i < 26; i++) {
            int res = getLongest(curr->next[i]);
            if (res > longest) {
                nextMove = i;
                longest = res;
            }
        }

        curr->nextMove = nextMove;
        return longest + 1;
    }

    string longestWord(vector<string> &words) {
        Trie *root = build(words);
        root->isWord = true;

        int longest = getLongest(root) - 1;

        string res;
        while (root->nextMove != -1) {
            res += root->nextMove + 'a';
            root = root->next[root->nextMove];
        }
        return res;
    }
};
// @leet end
