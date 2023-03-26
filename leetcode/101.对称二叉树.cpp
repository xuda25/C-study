/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 瀵圭О浜屽弶鏍�
 */
#include <queue>
#include <stack>

using namespace std;


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

// 递归方法
// class Solution {
// public:
//     bool compare(TreeNode* left, TreeNode* right)
//     {
//         if (left == nullptr && right != nullptr) return false;
//         else if (left != nullptr && right == nullptr) return false;
//         else if (left == nullptr && right == nullptr) return true;
//         else if (left->val != right->val) return false;

//         // 此时 剩下的结果就是  左右树 头节点相等 情况 那么继续下一层
//         //  此时要比较的就是 左树 右树的内侧   左树右树的外侧
//         bool inside = compare(left->right, right->left);
//         bool outside = compare(left->left, right->right);

//         return inside && outside;
//     }


//     bool isSymmetric(TreeNode* root) {
//         return compare(root->left, root->right);
//     }
// };


// 迭代
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == nullptr) return true;

        que.push(root->left);
        que.push(root->right);

        while (!que.empty())
        {
            TreeNode* l = que.front();
            que.pop();
            TreeNode* r = que.front();
            que.pop();
            
            // 该步很关键
            if (!l && !r)
                continue;

            if ((l == nullptr && r != nullptr) || (l != nullptr && r == nullptr) || (l->val != r->val))
                return false;

            que.push(l->right);
            que.push(r->left);
            que.push(l->left);
            que.push(r->right);
        }


        return true;
    }
};

// @lc code=end

