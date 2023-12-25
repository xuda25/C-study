/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int res = 0;
    vector<TreeNode*> node;
    void dfs(TreeNode* root, long long targetSum)
    {
        if (!root) return;
        if (root->val == targetSum)
        {
            ++res;
        }
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
        return;
    }

    void dfsNode(TreeNode* root)
    {
        if (!root) return;
        node.push_back(root);
        dfsNode(root->left);
        dfsNode(root->right);
    }

    int pathSum(TreeNode* root, int targetSum) {
        dfsNode(root);
        for (auto a : node)
            dfs(a, targetSum);
        return res;
    }
};
// @lc code=end

