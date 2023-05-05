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

// 递归
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         // 找不到节点
//         if (!root) return nullptr;
//         if (root->val == key)
//         {   
//             // 目标节点左右子节点为nullptr
//             if (!root->left && !root->right)
//             {
//                 delete root;
//                 return nullptr;
//             }
//             // 目标节点 左为空 右不空
//             else if (!root->left && root->right)
//             {
//                 TreeNode* node = root->right;
//                 delete root;
//                 return node;
//             }
//             // 右空 左不空
//             else if (!root->right && root->left)
//             {
//                 TreeNode* node = root->left;
//                 delete root;
//                 return node;
//             }
//             else if (root->left && root->left)
//             {
//                 TreeNode* cur = root->right;
//                 while (cur->left)
//                     cur = cur->left;
//                 cur->left = root->left;
//                 TreeNode* tmp = root;
//                 root = root->right;
//                 delete tmp;
//                 return root;
//             }
//         }
//         if (root->val > key) root->left = deleteNode(root->left, key);
//         if (root->val < key) root->right = deleteNode(root->right, key); 
//         return root;
//     }
// };


//适用于普通二叉树方法
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 找不到节点
        if (!root) return nullptr;
        if (root->val == key)
        {
            if (!root->right)
                return root->left;
            
            TreeNode* cur= root->right;
            while (cur->left)
                cur = cur->left;

            swap(root->val, cur->val);
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end

