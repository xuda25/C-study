/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 浜屽弶鏍戠殑鏈€灏忔繁搴�
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

// 递归法
// class Solution {
// public:
//     int result;
//     int min(TreeNode* root, int dep)
//     {   
//         dep += 1;
//         if (root->left == nullptr && root->right == nullptr)
//         {
//             result = result < dep ? result : dep;
//         }

//         if (root->left) min(root->left, dep);
//         if (root->right) min(root->right, dep);
        
//         return result;
//     }


//     int minDepth(TreeNode* root) {
//         result = INT32_MAX;
//         if (root)
//             return min(root, 0);
//         else
//             return 0;

//     }
// };


//迭代

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root)
            que.push(root);
        int dep = 0;
        while (!que.empty())
        {
            int size = que.size();
            ++dep;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
                if (cur->left == nullptr && cur->right == nullptr)  return dep;
            }
        }
        return dep;
    }
};
// @lc code=end

