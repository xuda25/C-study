/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <vector>
#include <stack>

using namespace std;

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if (root == nullptr)
//             return vector<int>();

//         stack<TreeNode*> st;
//         vector<int> ans;

//         TreeNode *cur = root;

//         while (cur != nullptr || !st.empty())
//         {
//             if (cur != nullptr)
//             {
//                 st.push(cur);
//                 cur = cur->left;
//             }
//             else
//             {
//                 ans.push_back(st.top()->val);
//                 cur = st.top()->right;
//                 st.pop();
//             }
//         }
//         return ans;
//     }
// };

// ͳһ������
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;

        if (root != nullptr)
            st.push(root);

        while (!st.empty())
        {   
            TreeNode *cur = st.top();
            if (cur != nullptr)
            {
                st.pop();

                if (cur->right) st.push(cur->right);
                st.push(cur);
                st.push(nullptr);
                if (cur->left)   st.push(cur->left);
            }
            else
            {
                st.pop();
                ans.push_back(st.top()->val);
                st.pop();
            }
        }

        return ans;
    }
};
// @lc code=end

