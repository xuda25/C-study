/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
//递归
// class Solution {
// public:
//     TreeNode* trimBST(TreeNode* root, int low, int high) {
//         if (!root) return nullptr;
//         if (root->val < low)
//         {   
//             TreeNode* right = trimBST(root->right, low, high);
//             return right;
//         }
//         if (root->val > high)
//         {
//             TreeNode* left = trimBST(root->left, low, high);
//             return left;
//         }
//         root->left = trimBST(root->left, low, high);
//         root->right = trimBST(root->right, low, high);
//         return root;
//     }
// };

//迭代
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root)  return nullptr;
        // 处理头节点
        while (root && (root->val < low || root->val > high))
        {
            if (root->val < low)
                root = root->right;
            else
                root = root->left;
        }

        TreeNode* cur = root;
        // 处理左子树
        while (cur)
        {
            while (cur->left && cur->left->val < low)
            {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }

        cur = root;
        // 处理右子树
        while (cur)
        {
            while (cur->right && cur->right->val > high)
            {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }        

        return root;
    }
};
// @lc code=end

