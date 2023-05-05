/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if (!root1) return root2;
//         if (!root2) return root1;

//         root1->val += root2->val;

//         root1->left = mergeTrees(root1->left, root2->left);
//         root1->right = mergeTrees(root1->right, root2->right);
        
//         return root1;
//     }
// };


// 迭代
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);

        while (!que.empty())
        {
            TreeNode* cur1 = que.front();
            que.pop();
            TreeNode* cur2 = que.front();
            que.pop();

            cur1->val += cur2->val;

            if (cur1->left && cur2->left)
            {
                que.push(cur1->left);
                que.push(cur2->left);
            }

            if (cur1->right && cur2->right)
            {
                que.push(cur1->right);
                que.push(cur2->right);
            }

            if (!cur1->left && cur2->left)
                cur1->left = cur2->left;

            if (!cur1->right && cur2->right)
                cur1->right = cur2->right;
        }

        return root1;
    }
};
// @lc code=end

