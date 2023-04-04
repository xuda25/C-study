/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 浠庝腑搴忎笌鍚庡簭閬嶅巻搴忓垪鏋勯€犱簩鍙夋爲
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

/*以后序遍历最后一个元素为头节点 进行切割*/
// 1.如果空数组 直接返回空
// 2.非空的话 先找后续遍历的最后一个值 作为头节点
// 3.找后序遍历点 在中序遍历中的位置 作为切割点
// 4.切分中序数组， 分为左右两个数组
// 5.切分后续数组  4.5 要保证循环边界不变原则
// 6.递归上述过程
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
        postorder.resize(postorder.size() - 1); // 丢掉最后一个值
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

