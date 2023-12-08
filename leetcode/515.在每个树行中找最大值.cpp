/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
// dfs
class Solution {
public:
    void dfs (vector<int>& res, TreeNode* root, int depth)
    {
        if (!root) return;
        if (res.size() == depth)
            res.push_back(INT32_MIN);
        res[depth] = root->val > res[depth] ? root->val : res[depth];

        dfs(res, root->left, depth + 1);
        dfs(res, root->right, depth + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        int depth = 0;
        dfs(res, root, depth);
        return res;
    }
};
// O(n)
// O(n)

// bfs也行 懒得写了
// @lc code=end

