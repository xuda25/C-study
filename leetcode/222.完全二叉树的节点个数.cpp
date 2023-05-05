/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 瀹屽叏浜屽弶鏍戠殑鑺傜偣涓暟
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

// 基本广度优先
// class Solution {
// public:
    
//     int countNodes(TreeNode* root) {
//         queue<TreeNode*> que;
//         if (root)
//             que.push(root);
//         int res = 0;
//         while (!que.empty())
//         {
//             int size = que.size();
//             for (int i = 0; i < size; ++i)
//             {
//                 TreeNode* cur = que.front();
//                 ++res;
//                 que.pop();
//                 if (cur->left)
//                     que.push(cur->left);
//                 if (cur->right)
//                     que.push(cur->right);
//             }
//         }    
//         return res;
//     }
// };

//递归
// class Solution {
// public:
//         int getSum(TreeNode* root, int &res)
//         {
//             if (!root->left && !root->right)    return res;


//             if (root->left)
//             {
//                 ++res;
//                 getSum(root->left, res);
//             } 
//             if (root->right)
//             {
//                 ++res;
//                 getSum(root->right, res);
//             }

//             return res;
//         }

//     int countNodes(TreeNode* root) {
//         if (!root)
//             return 0;

//         int res = 1;
//         return getSum(root, res);
//     }
// };

// 上述都把完全二叉树当作了 普通二叉树来做

// 正式的迭代

//  完全二叉树 一直找子树 一定是满二叉树
// 判断满二叉树的方法就是  同时向左、向右遍历  深度一样就是了
//  上述遍历两边的前提是  树是完全二叉树
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        int depthL = 0;
        int depthR = 0;
        // 遍历 左子树
        while (left)
        {
            left = left->left;
            ++depthL;
        }
        // 遍历 右子树
        while (right)
        {
            right = right->right;
            ++depthR;
        }

        if (depthL == depthR)
        {
            return (2 << depthL) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// @lc code=end

