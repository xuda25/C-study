/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] ‰∫åÂèâÊ†ëÁöÑÂ±ÇÂ∫èÈÅçÂéÜ
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
#include <vector>
#include <queue>
using namespace std;

// µ¸¥˙

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         queue<TreeNode*> que;

//         if(root != nullptr)
//             que.push(root);

//         while (!que.empty())
//         {
//             int size = que.size();
//             vector<int> ansTem;
//             for (int i = 0; i < size; ++i)
//             {      
//                 TreeNode *cur = que.front();
//                 if (cur->left) que.push(cur->left);
//                 if (cur->right) que.push(cur->right);
//                 ansTem.push_back(cur->val);
//                 que.pop();
//             }
//             ans.push_back(ansTem);
//         }

//         return ans;
//     }
// };


//µ›πÈ

class Solution {
public:

    void order(TreeNode *cur, vector<vector<int>> &ans, int depth)
    {
        if (cur == nullptr) return;
        if (ans.size() == depth) ans.push_back(vector<int>());

        ans[depth].push_back(cur->val);
        order(cur->left, ans, depth + 1);
        order(cur->right, ans, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       int depth = 0;

       order(root, ans, depth);
       return ans;
    }
};
// @lc code=end

