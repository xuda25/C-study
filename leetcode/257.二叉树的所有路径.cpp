/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 浜屽弶鏍戠殑鎵€鏈夎矾寰�
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

// 递归1
// class Solution {
// public:
//     void TreePaths(TreeNode* root, vector<int>& path, vector<string>& res)
//     {
//         path.push_back(root->val);

//         if (!root->left && !root->right)
//         {
//             string tem;
//             for (int i = 0; i < path.size() - 1; ++i)
//             {
//                 tem += to_string(path[i]);
//                 tem += "->";
//             }
//             tem += to_string(path[path.size() - 1]);
//             res.push_back(tem);
//             return;
//         }

//         if (root->left)
//         {
//             TreePaths(root->left, path, res);
//             path.pop_back();
//         }

//         if (root->right)
//         {
//             TreePaths(root->right, path, res);
//             path.pop_back();
//         }
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> ans;
//         vector<int> path;
//         TreePaths(root, path, ans);
//         return ans;
//     }
// };

// 递归2
// class Solution {
// public:
//     void TreePaths(TreeNode* root, string path, vector<string>& res)
//     {
//         path += to_string(root->val);

//         if (!root->left && !root->right)
//         {
//             res.push_back(path);
//             return;
//         }

//         if (root->left)
//         {
//             path += "->";
//             TreePaths(root->left, path, res);
//             path.pop_back();
//             path.pop_back();
//         }

//         if (root->right)
//         {
//             path += "->";
//             TreePaths(root->right, path, res);
//             path.pop_back();
//             path.pop_back();
//         }
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> ans;
//         string path;
//         TreePaths(root, path, ans);
//         return ans;
//     }
// };


// 迭代
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        stack<string> paths;
        stack<TreeNode*> nodes;
        nodes.push(root);
        paths.push(to_string(root->val));

        while(!nodes.empty())
        {
            TreeNode* node = nodes.top();
            string path = paths.top();
            nodes.pop();
            paths.pop();

            if (!node->left && !node->right)
            {
                ans.push_back(path);
            }

            if (node->right)
            {
                nodes.push(node->right);
                paths.push(path + "->" + to_string(node->right->val));
            }

            if (node->left)
            {
                nodes.push(node->left);
                paths.push(path + "->" + to_string(node->left->val));
            }
        }
        return ans;
    }
};
// @lc code=end

