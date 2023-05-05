/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 宸﹀彾瀛愪箣鍜�
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
// 迭代

// class Solution {
// public:
//     // int sum(TreeNode* root, int& res)
//     // {   

//     //     if (!root->left && !root->right)
//     //     {
//     //         res += root->val;
//     //         return res;
//     //     }
        
//     //     sum(root->left, res);
//     //     sum(root->right, res);

//     //     return res;
//     // }

//     int sumOfLeftLeaves(TreeNode* root) {
//         queue<TreeNode*> que;

//         if (root)
//             que.push(root);

//         int ans = 0;

//         while (!que.empty())
//         {
//             int size = que.size();
            
//             for (int i = 0; i < size; ++i)
//             {
//                 TreeNode* cur = que.front();
//                 que.pop();
//                 if (cur->left)
//                 {
//                     que.push(cur->left);
//                     if (!cur->left->left && !cur->left->right)
//                         ans += cur->left->val;
//                 }

//                 if (cur->right)
//                     que.push(cur->right);
//             }
//         }
//         return ans;
//     }
// };

//递归
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right)    return 0;

        int left = sumOfLeftLeaves(root->left);
        if (root->left && !root->left->left && !root->left->right)
        {
            left += root->left->val;
        }

        int right = sumOfLeftLeaves(root->right);

        int sum = left + right;
        return sum;
    }
};
// @lc code=end

