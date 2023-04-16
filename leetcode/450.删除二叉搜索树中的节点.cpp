/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* pre = nullptr;
    void travel(TreeNode* root, int key)
    {
        if(!root) return;
        if (root->val == key)
        {   
            TreeNode* left = root->left;
            if (root->val > pre->val)
            {
                pre->right = root->right;
                TreeNode* node = pre->right;
                while (node->left)
                    node = node->left;
                node->left = left;
            }
            else
            {
                pre->left = root->right;
                TreeNode* node = pre->left;
                while (node->left)
                    node = node->left;
                node->left = left;
            }
        }

        if (root->val > key)
        {   
            pre = root;
            travel(root->left, key);
        }

        if (root->val < key)
        {   
            pre = root;
            travel(root->right, key);
        }

    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (!root->left && !root->right && root->val == key)
            return nullptr;
        else if (!root->left && !root->right && root->val != key)
            return root;

        if (root->val == key)
        {

            TreeNode* head = root->right;
            TreeNode* node = head->left;
            while (node->left)
                node = node->left;
            node->left = root->left;
            return head;
        }
        travel(root, key);
        return root;
    }
};
// @lc code=end

