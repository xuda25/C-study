/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 缈昏浆浜屽弶鏍�
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

// 递归法
// class Solution {
// public:

//     void invert(TreeNode *root)
//     {
//         if (root == nullptr) return ;
//         TreeNode *tem = root->left;
//         root->left = root->right;
//         root->right = tem;
//         invert(root->left);
//         invert(root->right);
//     }

//     TreeNode* invertTree(TreeNode* root) {
//         TreeNode *cur = root;
//         invert(cur);
//         return root;
//     }
// };
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

// 迭代法1  前序遍历
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         stack<TreeNode*> st;
//         if (root != nullptr) st.push(root);

//         while (!st.empty())
//         {
//             TreeNode* cur = st.top();
//             st.pop();
//             swap(cur->left, cur->right);
//             if (cur->right) st.push(cur->right);
//             if (cur->left) st.push(cur->left);
//         }    
//         return root;
//     }
// };


// 统一迭代法 中序迭代 进行翻转
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         stack<TreeNode*> st;
//         if (root != nullptr)
//             st.push(root);
        
//         while (!st.empty())
//         {
//             TreeNode* cur = st.top();

//             if (cur != nullptr)
//             {
//                 st.pop();

//                 if (cur->right) st.push(cur->right);

//                 st.push(cur);
//                 st.push(nullptr);

//                 if (cur->left) st.push(cur->left);

//             }
//             else
//             {
//                 st.pop();
//                 swap(st.top()->left, st.top()->right);
//                 st.pop();
//             }
//         }
//         return root;
//     }
// };


// 广度遍历 翻转
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr)
            que.push(root);
        
        while (!que.empty())
        {

            int size = que.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = que.front();
                que.pop();
                swap(cur->left, cur->right);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        
        return root;
    }
};


// @lc code=end

