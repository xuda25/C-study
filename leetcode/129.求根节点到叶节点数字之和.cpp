/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int result = 0;
    vector<int> path;

    int vecToInt(vector<int>& path)
    {   
        int res = 0;
        for (int i = 0; i < path.size(); ++i)
        {
            res = res * 10 + path[i];
        }

        return res;
    }

    void travel(TreeNode* cur)
    {   
        
        if (!cur->left && !cur->right)
        {
            result += vecToInt(path);
            return;
        }

        // 中


        // 左
        if (cur->left)
        {
            path.push_back(cur->left->val);
            travel(cur->left);
            path.pop_back();
        }

        //右
        if (cur->right)
        {
            path.push_back(cur->right->val);
            travel(cur->right);
            path.pop_back();
        }

        return;
    }

    int sumNumbers(TreeNode* root) {
        path.push_back(root->val);
        travel(root);
        return result;
    }
};
// @lc code=end

