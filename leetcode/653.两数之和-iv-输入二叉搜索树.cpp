/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
// 哈希表加dfs
class Solution {
public:
    unordered_set<int> s;

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (s.count(k - root->val)) return true;

        s.emplace(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

//中序遍历
class Solution {
public:
    vector<int> num;

    void dfs(TreeNode* root)
    {   
        if (!root) return;
        dfs(root->left);
        num.emplace_back(root->val);
        dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int l = 0, r = num.size() - 1;
        while (l < r)
        {
            if (num[l] + num[r] == k)
                return true;
            else if (num[l] + num[r] > k)
                r -= 1;
            else
                l += 1;
        }

        return false;
    }
};
// @lc code=end

