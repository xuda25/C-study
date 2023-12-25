/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    vector<int> res;
    map<int, int> mp;
// 后序遍历算子树和
    void dfs(TreeNode* root)
    {
        if (!root) return;

        dfs(root->left);
        dfs(root->right);
        if (!root->left && !root->right)
            return;
        else
        {
            if (!root->left)
                root->val += root->right->val;
            else if (!root->right)
                root->val += root->left->val;
            else
                root->val += (root->left->val + root->right->val);
        }
    }

    // 插入map
    void dfsM(TreeNode* root)
    {
        if (!root) return;

        ++mp[root->val];
        dfsM(root->left);
        dfsM(root->right);
        return;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        dfsM(root);
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        int max = v[0].second;
        for (auto& a : v)
            if (a.second == max)
                res.push_back(a.first);

        return res;
    }
};

// 优化
class Solution {
public:
    vector<int> res;
    unordered_map<int, int> mp;
    int maxN = 0;
// 后序遍历算子树和
    void dfs(TreeNode* root)
    {
        if (!root) return;

        dfs(root->left);
        dfs(root->right);
        if (!root->left && !root->right)
            return;
        else
        {
            if (!root->left)
                root->val += root->right->val;
            else if (!root->right)
                root->val += root->left->val;
            else
                root->val += (root->left->val + root->right->val);
        }
        
    }

    // 插入map
    void dfsM(TreeNode* root)
    {
        if (!root) return;

        ++mp[root->val];
        maxN = max(maxN, mp[root->val]);
        dfsM(root->left);
        dfsM(root->right);
        return;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        dfsM(root);
        for (auto& a : mp)
            if (a.second == maxN)
                res.push_back(a.first);

        return res;
    }
};
// @lc code=end

