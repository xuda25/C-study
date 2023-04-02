/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的倄1�7
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

// ����
// �������
// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {
//         queue<TreeNode*> que;
//         if (root)
//             que.push(root);
//         int ans;
//         while (!que.empty())
//         {
//             int size = que.size();
//             ans = que.front()->val;
//             for (int i = 0; i < size; ++i)
//             {
//                 TreeNode* cur = que.front();
//                 que.pop();

//                 if (cur->left)
//                     que.push(cur->left);

//                 if (cur->right)
//                     que.push(cur->right);
//             }
//         }
//         return ans;
//     }
// };

// �ݹ�
class Solution {
public:
    int maxDep = INT32_MIN;
    int result;
    void travel(TreeNode* root, int dep)
    {
        if(!root->left && !root->right)
        {
            if (dep > maxDep)
            {
                maxDep = dep;
                result = root->val;
            }
            return;
        }

        // ��

        // ��
        if (root->left)
        {
            ++dep;
            travel(root->left, dep);
            --dep;  //���� --dep
        }

        // ��
        if (root->right)
        {
            ++dep;
            travel(root->right, dep);
            --dep;
        }

        return;
    }


    int findBottomLeftValue(TreeNode* root) {
        travel(root, 0);
        return result;
    }
};
// @lc code=end

