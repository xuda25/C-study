/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 浜屽弶鏍戠殑鍚庡簭閬嶅巻
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

//普通迭代

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         if (root == nullptr)
//             return vector<int>();
//         stack<TreeNode*> st;
//         vector<int> ans;
        
//         st.push(root);

//         while (!st.empty())
//         {   
//             TreeNode *cur = st.top();
//             st.pop();
//             ans.push_back(cur->val);

//             if (cur->left) st.push(cur->left);
//             if (cur->right) st.push(cur->right);
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };


// 统一迭代方式

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if (root !=nullptr)
            st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();

            if (node != nullptr)
            {
                st.pop();
                st.push(node);
                st.push(nullptr);
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);

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

