/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;

    int dfs(TreeNode* root)
    {
        if (!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        int l1 = 0, r1 = 0;
        if (root->left && root->val == root->left->val)
            l1 = l + 1;
        if (root->right && root->val == root->right->val)
            r1 = r + 1;
        res = max(res, l1 + r1);

        return max(l1, r1);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res; 
    }
};
// @lc code=end

