/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 鍙︿竴妫垫爲鐨勫瓙鏍�
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
    bool SubTree(TreeNode* root, TreeNode* sub)
    {
        if (!root && !sub) return true;
        else if ((!root && sub) || (root && !sub) || (root->val != sub->val)) return false;

        return SubTree(root->left, sub->left) && SubTree(root->right, sub->right);
    }

    bool dfs(TreeNode* root, TreeNode* sub)
    {   
        if (!root)
            return false;

        bool ans = SubTree(root, sub);
        if (ans)
        {
            return true;
        }
        else
            return dfs(root->left, sub) || dfs(root->right, sub);
    }



    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};
// @lc code=end

