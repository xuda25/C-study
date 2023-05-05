/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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

// �����������
// class Solution {
// public:
    
//     int countNodes(TreeNode* root) {
//         queue<TreeNode*> que;
//         if (root)
//             que.push(root);
//         int res = 0;
//         while (!que.empty())
//         {
//             int size = que.size();
//             for (int i = 0; i < size; ++i)
//             {
//                 TreeNode* cur = que.front();
//                 ++res;
//                 que.pop();
//                 if (cur->left)
//                     que.push(cur->left);
//                 if (cur->right)
//                     que.push(cur->right);
//             }
//         }    
//         return res;
//     }
// };

//�ݹ�
// class Solution {
// public:
//         int getSum(TreeNode* root, int &res)
//         {
//             if (!root->left && !root->right)    return res;


//             if (root->left)
//             {
//                 ++res;
//                 getSum(root->left, res);
//             } 
//             if (root->right)
//             {
//                 ++res;
//                 getSum(root->right, res);
//             }

//             return res;
//         }

//     int countNodes(TreeNode* root) {
//         if (!root)
//             return 0;

//         int res = 1;
//         return getSum(root, res);
//     }
// };

// ����������ȫ������������ ��ͨ����������

// ��ʽ�ĵ���

//  ��ȫ������ һֱ������ һ������������
// �ж����������ķ�������  ͬʱ�������ұ���  ���һ��������
//  �����������ߵ�ǰ����  ������ȫ������
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        int depthL = 0;
        int depthR = 0;
        // ���� ������
        while (left)
        {
            left = left->left;
            ++depthL;
        }
        // ���� ������
        while (right)
        {
            right = right->right;
            ++depthR;
        }

        if (depthL == depthR)
        {
            return (2 << depthL) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// @lc code=end

