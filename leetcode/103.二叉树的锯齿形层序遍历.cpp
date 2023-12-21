/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
class Solution {
public:
// 明显层序遍历  双端进出 用deque
// 左出则右进  左先进右再进
// 右出则左进  右先进右再进
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        deque<TreeNode*> de;
        de.push_back(root);
        vector<vector<int>> res;
        bool lSign = true; // 左出
        while (!de.empty())
        {
            int size = de.size();
            vector<int> tmp;
            if (lSign) // 左出右进
            {
                for (int i = 0; i < size; ++i)
                {
                    TreeNode* cur = de.front();
                    de.pop_front();
                    tmp.push_back(cur->val);
                    if (cur->left) de.push_back(cur->left);
                    if (cur->right) de.push_back(cur->right);
                }
                res.push_back(tmp);
                lSign = false;
            }
            else
            {
                for (int i = 0; i < size; ++i)
                {
                    TreeNode* cur = de.back();
                    de.pop_back();
                    tmp.push_back(cur->val);
                    if (cur->right) de.push_front(cur->right);
                    if (cur->left) de.push_front(cur->left);
                }
                res.push_back(tmp);
                lSign = true;
            }
        }
        return res;
    }
};
// @lc code=end

