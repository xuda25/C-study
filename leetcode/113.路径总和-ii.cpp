/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
//�ݹ�
class Solution {
public:
    vector<int>tem;
    vector<vector<int>> ans;
    void travel(TreeNode* root, int count)
    {   
        tem.push_back(root->val);

        if (!root->left && !root->right && count == 0)
            ans.push_back(tem);
        if (!root->left && !root->right && count != 0)
            return;

        if (root->left)
        {
            travel(root->left, count - root->left->val);
            tem.pop_back();
        }

        if (root->right)
        {
            travel(root->right, count - root->right->val);
            tem.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return vector<vector<int>>();
        travel(root, targetSum - root->val);
        return ans;
    }
};

// @lc code=end

