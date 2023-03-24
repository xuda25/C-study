/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return vector<int>();
        stack<TreeNode*> st;
        vector<int> ans;
        
        st.push(root);

        while (!st.empty())
        {   
            TreeNode *cur = st.top();
            st.pop();
            ans.push_back(cur->val);

            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

