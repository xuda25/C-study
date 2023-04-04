/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 浠庡墠搴忎笌涓簭閬嶅巻搴忓垪鏋勯€犱簩鍙夋爲
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
    // TreeNode* travel(vector<int>& preorder, vector<int>& inorder)
    // {
    //     // 1. 空遍历 直接返回空
    //     if (preorder.size() == 0) return nullptr;
    //     // 2. pre头节点为root
    //     TreeNode* root = new TreeNode(preorder[0]);
    //     if (preorder.size() == 0) return root;
    //     // 3.找中序中找头节点的值
    //     int index;
    //     for (index = 0; index < inorder.size(); ++index)
    //         if (inorder[index] == root->val)
    //             break;

    //     // 4.分割中序
    //     vector<int>leftin(inorder.begin(), inorder.begin() + index);
    //     vector<int>rightin(inorder.begin() + index + 1, inorder.end());

    //     // 5.分割前序
    //     vector<int>leftpre(preorder.begin() + 1, preorder.begin() + 1 + leftin.size());
    //     vector<int>rightpre(preorder.begin() + 1 + leftin.size(), preorder.end());

    //     root->left = travel(leftpre, leftin);
    //     root->right = travel(rightpre, rightin);

    //     return root;
    // }

    TreeNode* travel(vector<int>& preorder, int preorderbegin, int preorderend, vector<int>& inorder, int inorderbegin, int inorderend)
    {
        if (preorderend - preorderbegin == 0) return nullptr;

        int rootVal = preorder[preorderbegin];
        TreeNode* root = new TreeNode(rootVal);

        if (preorderend - preorderbegin == 1) return root;

        int deindex;
        for (deindex = inorderbegin; deindex < inorderend; ++deindex)
            if (inorder[deindex] == rootVal)
                break;

        int leftInorderBegin = inorderbegin;
        int leftInorderEnd = deindex;
        int rightInorderBegin = deindex + 1;
        int rightInorderEnd = inorderend;

        int leftPreorderBegin = preorderbegin + 1;
        int leftPreorderEnd = preorderbegin + 1 + deindex - inorderbegin;
        int rightPreorderBegin = preorderbegin + 1 + deindex - inorderbegin;
        int rightPreorderEnd = preorderend;

        root->left = travel(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = travel(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return travel(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end

