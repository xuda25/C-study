/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 璺緞鎬诲拰
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
// 自己的递归  有点麻烦了
// class Solution {
// public:
//     int res = 0;

//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if (!root)
//             return false;

//         res += root->val;

//         if (!root->left && !root->right && res != targetSum)
//         {
//             return false;
//         }

//         if (!root->left && !root->right && res == targetSum)
//             return true;

//         if (root->left)
//         {
//             bool l = hasPathSum(root->left, targetSum);
//             if (l)
//                 return true;
//             else
//                 res -= root->left->val;
//         }
            
//         if (root->right)
//         {
//             bool r = hasPathSum(root->right, targetSum);
//             if (r)
//                 return true;
//             else
//                 res -= root->right->val;
//         }
        
//         return false;
//     }
// };

// carl的递归
// class Solution {
// public:
//     bool travel(TreeNode* root, int count)
//     {
//         if (!root->left && !root->right && count == 0) return true;
//         if (!root->left && !root->right) return false;

//         if (root->left)
//             if (travel(root->left, count - root->left->val)) return true;

//         if (root->right)
//             if (travel(root->right, count - root->right->val)) return true;

//         return false;
//     }

//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if (!root) return false;

//         return travel(root, targetSum - root->val);
//     }
// };

//迭代

class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;

        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->val));

        while (!st.empty())
        {
            auto cur = st.top();
            st.pop();

            if (!cur.first->left && !cur.first->right && cur.second == targetSum)   return true;

            if (cur.first->right)
                st.push(pair<TreeNode*, int>(cur.first->right, cur.second + cur.first->right->val));

            if (cur.first->left)
                st.push(pair<TreeNode*, int>(cur.first->left, cur.second + cur.first->left->val));
        }

        return false;
    }
};
// @lc code=end

