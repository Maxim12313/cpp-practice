#include "headers.hpp"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {
    }
};

// @leet start
class Solution {
public:
    // creates copy from tree rooted at root
    TreeNode *copy(TreeNode *root) {
        if (!root)
            return nullptr;
        TreeNode *curr = new TreeNode(root->val);
        curr->left = copy(root->left);
        curr->right = copy(root->right);
        return curr;
    }

    void add(vector<TreeNode *> &left, vector<TreeNode *> &right,
             TreeNode *curr, vector<TreeNode *> &ans) {
        for (TreeNode *l : left) {
            curr->left = l;
            for (TreeNode *r : right) {
                curr->right = r;
                ans.push_back(copy(curr));
            }
        }
    }

    vector<TreeNode *> build(int lo, int hi,
                             map<pair<int, int>, vector<TreeNode *>> &memo) {
        // if lo > hi? nullptr case?
        if (lo > hi)
            return {nullptr};

        if (lo == hi)
            return {new TreeNode(lo)};

        pair<int, int> key = {lo, hi};
        if (memo.count(key))
            return memo[key];

        vector<TreeNode *> ans;
        for (int mid = lo; mid <= hi; mid++) {
            vector<TreeNode *> left = build(lo, mid - 1, memo);
            vector<TreeNode *> right = build(mid + 1, hi, memo);
            TreeNode *curr = new TreeNode(mid);
            add(left, right, curr, ans);
        }

        return memo[key] = ans;
    }

    // when no more, copy and add to answer
    vector<TreeNode *> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode *>> memo;
        vector<TreeNode *> ans = build(1, n, memo);
        return ans;
    }
};
// @leet end
