/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
// 一眼前序遍历
    vector<TreeNode*> v;
    void dfs(TreeNode* root)
    {
        if (!root) return;

        v.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        if (!root) return;
        dfs(root);

        for (int i = 0; i < v.size(); ++i)
        {
            v[i]->left = nullptr;
            if (i + 1 < v.size())
                v[i]->right = v[i+1];
            else
                v[i]->right = nullptr;
        }
    }
};

// 找前驱节点
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur)
        {
            if (!cur->left)
                cur = cur->right;
            else
            {
                TreeNode* r = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
                TreeNode* tmp = cur;
                while (tmp->right)
                    tmp = tmp->right;
                tmp->right = r;
                cur = cur->right;
            }
        }
    }
};
// @lc code=end

