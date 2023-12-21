/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 鐩稿悓鐨勬爲
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
    bool SameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q != nullptr)   return false;
        else if (p != nullptr && q == nullptr)  return false;
        else if (p == nullptr && q == nullptr) return true;
        else if (p->val != q->val) return false;
        // 此时只剩下  位置相同 值也相同  继续向下递归

        bool l = SameTree(p->left, q->left);
        bool r = SameTree(p->right, q->right);

        return l && r;
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        return SameTree(p, q);
    }
};


//
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (q && !p) return false;
        if (!q && p) return false;

        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end

