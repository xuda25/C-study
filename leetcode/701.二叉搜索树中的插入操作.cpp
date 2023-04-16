/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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

// 递归
// class Solution {
// public:
//     TreeNode* parent;
//     void travel(TreeNode* root, int val)
//     {
//         if (!root)
//         {
//             TreeNode* node = new TreeNode(val);
//             if (parent->val < val) parent->right = node;
//             if (parent->val > val) parent->left = node; 
//             return;
//         }

//         parent = root;

//         if (root->val > val) travel(root->left, val);
//         if (root->val < val) travel(root->right, val);
//         return;
//     }

//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if (!root)
//         {
//             root = new TreeNode(val);
//         }
//         travel(root, val);
//         return root;
//     }
// };

// 迭代

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
        {
            root = new TreeNode(val);
            return root;
        }

        TreeNode* cur = root;
        TreeNode* pre = root;

        while (cur)
        {
            if (cur->val > val)
            {
                pre = cur;
                cur = cur->left;
            }
            else
            {
                pre = cur;
                cur = cur->right;
            }
        }

        TreeNode* node = new TreeNode(val);

        if (val > pre->val)
            pre->right = node;
        else
            pre->left = node;

        return root;
    }
};
// @lc code=end

