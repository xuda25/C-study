/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
// 第一思路： 广度优先从上到下遍历完  翻转结果数组
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)  return vector<vector<int>>();
        vector<vector<int>> res;
        deque<TreeNode*> de;
        de.push_back(root);
        
        while (!de.empty())
        {
            int size = de.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = de.front();
                de.pop_front();
                tmp.push_back(cur->val);
                if (cur->left) de.push_back(cur->left);
                if (cur->right) de.push_back(cur->right);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// O(n)
// O(n)



// @lc code=end

