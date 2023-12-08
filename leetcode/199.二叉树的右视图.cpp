/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
// 广度优先  取每层最后一个元素
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if (!root) return vector<int>();
//         vector<int> res;
//         deque<TreeNode*> de;
//         de.push_back(root);

//         while (!de.empty())
//         {
//             int size = de.size();
//             for (int i = 0; i < size; ++i)
//             {
//                 TreeNode* cur = de.front();
//                 de.pop_front();
//                 if (cur->left) de.push_back(cur->left);
//                 if (cur->right) de.push_back(cur->right);
//                 if (i == size - 1)
//                     res.push_back(cur->val);
//             }  
//         }

//         return res;
//     }
// };

// O(n)
// O(n)

// dfs
class Solution {
public:
    void dfs(vector<int>& res, TreeNode* root, int depth)
    {
        if (!root) return;
        if (depth == res.size()) res.push_back(root->val);

        dfs(res, root->right, depth + 1);
        dfs(res, root->left, depth + 1);
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int depth = 0;
        dfs(res, root, depth);
        return res;
    }
};
// @lc code=end

