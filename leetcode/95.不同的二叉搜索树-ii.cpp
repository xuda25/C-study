/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
// 
    vector<TreeNode*> generateTrees(int begin, int end)
    {
        if (begin > end) return {nullptr};

        vector<TreeNode*> allTrees;

        for (int i = begin; i <= end; ++i)
        {
            vector<TreeNode*> leftTree = generateTrees(begin, i-1);
            vector<TreeNode*> rightTree = generateTrees(i+1, end);


            for (auto& l : leftTree)
                for (auto& r : rightTree)
                {
                    TreeNode* curR = new TreeNode(i);
                    curR->left = l;
                    curR->right = r;
                    allTrees.emplace_back(curR);
                }
        }

        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};
// @lc code=end

