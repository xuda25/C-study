/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 朢�大二叉树
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
// 1.
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         if (nums.size() == 0) return nullptr;
//         // 寻找朢�大��1�7
//         int index = 0;
//         int max = nums[0];
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             if (nums[i] > max)
//             {
//                 max = nums[i];
//                 index = i;
//             }
//         }

//         // 建立根节炄1�7
//         int treeVal = nums[index];
//         TreeNode* root = new TreeNode(treeVal);
        
//         // 左树、右栄1�7 数组  
//         vector<int> leftT(nums.begin(), nums.begin() + index);
//         vector<int> rightT(nums.begin() + index + 1, nums.end());

//         root->left = constructMaximumBinaryTree(leftT);
//         root->right = constructMaximumBinaryTree(rightT);

//         return root;
//     }
// };

class Solution {
public:
    TreeNode* travel(vector<int>& nums, int left, int right)
    {
        if (right - left <= 0) return nullptr;

        int index = left;
        for (int i = left; i < right; ++i)
            if (nums[i] > nums[index])
                index = i;

        TreeNode* root = new TreeNode(nums[index]);

        root->left = travel(nums, left, index);
        root->right = travel(nums, index + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return travel(nums, 0, nums.size());
    }
};


// @lc code=end

