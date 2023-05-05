/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

// 因为是搜索二叉树 变为数组来做
// class Solution {
// public:
//     vector<int> tra;
//     void travel(TreeNode* root)
//     {
//         if (!root) return;

//         travel(root->left);

//         tra.push_back(root->val);

//         travel(root->right);
//     }

//     int getMinimumDifference(TreeNode* root) {
//         travel(root);

//         int min = __INT_MAX__;

//         for (int i = 0; i < tra.size() - 1; ++i)
//         {
//             if (tra[i + 1] - tra[i] < min)
//                 min = tra[i + 1] - tra[i];
//         }
//         return min;
//     }
// };


// 递归
// class Solution {
// public:
//     int min = __INT_MAX__;
//     TreeNode* pre = nullptr;

//     void travel(TreeNode* root)
//     {
//         if (!root) return;

//         travel(root->left);

//         if (pre && root->val - pre->val < min)
//             min = root->val - pre->val;
//         pre = root;

//         travel(root->right);

//         return;
//     }
    
//     int getMinimumDifference(TreeNode* root) {
//         travel(root);
//         return min;
//     }
// };

//迭代
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int min = __INT_MAX__;

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
                if (pre && cur->val - pre->val < min)
                    min = cur->val - pre->val;

                pre = cur;
                cur = cur->right;
            }
        }
        return min;
    }
};
// @lc code=end

