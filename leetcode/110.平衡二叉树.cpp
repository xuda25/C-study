/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 骞宠　浜屽弶鏍�
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
//     int getH(TreeNode* root)
//     {
//         if (!root) return 0;

//         int left = getH(root->left);
//         if (left == -1) return -1;
//         int right = getH(root->right);
//         if (right == -1) return -1;
//         return abs(left - right) <= 1 ? 1 + max(left, right) : -1;
//     }

//     bool isBalanced(TreeNode* root) {
//         if (!root) return true;

//         return getH(root) == -1 ? false : true;
//     }
// };

// 迭代
class Solution {
public:
    int getMaxDep(TreeNode* root)
    {
        stack<TreeNode*> st;
        if (root)
            st.push(root);
        int dep = 0;
        int res = 0;

        while (!st.empty())
        {
            TreeNode* cur = st.top();

            if (cur)
            {
                st.pop();
                st.push(cur);
                st.push(nullptr);
                ++dep;
                if (cur->right) st.push(cur->right);
                if (cur->left) st.push(cur->left);
            }
            else
            {
                st.pop();
                st.pop();
                --dep;
            }
            res = res < dep ? dep : res;
        }

        return res;
    }


    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        if (root)
            st.push(root);
        
        while(!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();

            if (abs(getMaxDep(cur->left) - getMaxDep(cur->right)) > 1)
                return false;
            
            if (cur->right) st.push(cur->right);

            if (cur->left) st.push(cur->left);
        }
        return true;
    }
};
// @lc code=end

