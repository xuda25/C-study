/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构��二叉树
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

/*�Ժ���������һ��Ԫ��Ϊͷ�ڵ� �����и�*/
// 1.��������� ֱ�ӷ��ؿ�
// 2.�ǿյĻ� ���Һ������������һ��ֵ ��Ϊͷ�ڵ�
// 3.�Һ�������� ����������е�λ�� ��Ϊ�и��
// 4.�з��������飬 ��Ϊ������������
// 5.�зֺ�������  4.5 Ҫ��֤ѭ���߽粻��ԭ��
// 6.�ݹ���������
class Solution {
public:
    TreeNode* travel(vector<int>& inorder, vector<int>& postorder)
    {
        // 1
        if (postorder.size() == 0) return nullptr;
        // 2
        int rootVal = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(rootVal);

        if (postorder.size() == 1) return root;
        // 3
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); ++delimiterIndex)
        {
            if (inorder[delimiterIndex] == rootVal)
                break;
        }

        // 4  [0, delemiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
            // [delemiterIndex + 1, end];
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
        // 5
        postorder.resize(postorder.size() - 1); // �������һ��ֵ
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
        // 6
        root->left = travel(leftInorder, leftPostorder);
        root->right = travel(rightInorder, rightPostorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return travel(inorder, postorder);
    }
};
// @lc code=end

