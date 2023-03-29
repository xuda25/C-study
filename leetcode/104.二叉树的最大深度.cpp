/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的朢�大深庄1�7
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

// ��һ���Լ�д�����ĵݹ� ������
// class Solution {
// public:
//     int depth(TreeNode* root, int dep)
//     {
//         if (root == nullptr) return dep;

//         dep += 1;
//         int l = depth(root->left, dep);
//         int r = depth(root->right, dep);

//         return max(l, r);
//     }

//     int maxDepth(TreeNode* root) {
//         return depth(root, 0);
//     }
// };

// ǰ������ĵݹ�

// class Solution {
// public:
//     int result;

//     void getdepth(TreeNode* root, int dep)
//     {
//         result = dep > result ? dep : result;  // ��

//         if (root->left == nullptr && root->right == nullptr) return;
//         // ��
//         if (root->left)  
//         {
//             ++dep;
//             getdepth(root->left, dep);
//             --dep;
//         }

//         //��
//         if (root->right)
//         {
//             ++dep;
//             getdepth(root->right, dep);
//             --dep;
//         }
//     }

//     int maxDepth(TreeNode* root) {
//         result = 0;
//         if (root == nullptr) return 0;
//         else
//             getdepth(root, 1);
//         return result;
//     }
// };


//����
class Solution {
public:
    
    int maxDepth(TreeNode* root) {
        int dep = 0;
        queue<TreeNode*> que;
        if (root)
            que.push(root);

        while (!que.empty())
        {
            ++dep;
            int size = que.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left)  que.push(cur->left);

                if (cur->right) que.push(cur->right);
            }
        }

        return dep;
    }
};
// @lc code=end

