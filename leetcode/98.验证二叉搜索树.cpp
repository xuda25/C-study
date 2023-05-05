/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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

// 递归  利用数组，  搜索二叉树 中序遍历为递增数组
// class Solution {
// public:
//     vector<int> ans;

//     void travel(TreeNode* root)
//     {
//         if (!root) return;
        
//         travel(root->left);

//         ans.push_back(root->val);

//         travel(root->right);

//         return;
//     }
//     bool isValidBST(TreeNode* root) {
//         travel(root);

//         for (int i = 0; i < ans.size() - 1; ++i)
//         {
//             if (ans[i + 1] <= ans[i])
//                 return false;
//         }

//         return true;
//     }
// };

// 普通递归

// class Solution {
// public:
//     TreeNode* pre = nullptr;
//     bool isValidBST(TreeNode* root) {
//         if (!root) return true;

//         bool left = isValidBST(root->left);

//         if (pre && pre->val >= root->val) return false;
//         pre = root;

//         bool right = isValidBST(root->right);

//         return left && right;
//     }
// };

// 迭代
class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        while (cur || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();

                if (pre && pre->val >= cur->val) return false;
                pre = cur;

                cur = cur->right;
            }
        }

        return true;
    }
};
// @lc code=end

