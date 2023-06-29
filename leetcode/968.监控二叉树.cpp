/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int result;
    
    int travel(TreeNode* root)
    {
        if (root == nullptr)    return 2; //有覆盖
        // 后续遍历
        int left = travel(root->left);
        int right = travel(root->right);

        //中
        //情况一  叶子节点都被覆盖 则父节点未被覆盖
        if (left == 2 && right == 2) return 0;

        //情况二  叶子节点至少有一个未被覆盖
        // 1. left == 0 right == 2
        // 2. left == 2 right == 0
        // 3. left == 0 right == 1
        // 4. left == 1 right == 0
        // 5. left == 0 right == 0
        if (left == 0 || right == 0)
        {
            ++result;
            return 1;
        }

        //情况三  左右节点有一个摄像头
        // 1. left == 1 right == 1
        // 2. left == 1 right == 2
        // 3. left == 2 right == 1
        if (left == 2 || right == 2) return 2;
    }

    int minCameraCover(TreeNode* root) {
        result = 0;
        if (travel(root) == 0) // root未覆盖 
            ++result;
        return result;
    }
};
// @lc code=end

