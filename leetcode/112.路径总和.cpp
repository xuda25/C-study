/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
class Solution {
public:
    bool res = false;

    void travel(TreeNode* root, int& targetSum)
    {
        if (!root->left && !root->right)
        {
            if (targetSum == 0)
                res = true;
            return;
        }

        // 左右
        if (root->left)
        {
            targetSum -= root->left->val;
            travel(root->left, targetSum);
            targetSum += root->left->val;
        }

        //右
        if (root->right)
        {
            targetSum -= root->right->val;
            travel(root->right, targetSum);
            targetSum += root->right->val;
        }
        
        return;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return root->val == targetSum;
        int target = targetSum - root->val;
        travel(root, target);
        return res;
    }
};
// @lc code=end

