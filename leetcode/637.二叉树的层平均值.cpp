/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
// 层序遍历完每组求平均
class Solution {
public:
    double average(vector<int> val)
    {
        double sum = 0;
        for (int i = 0; i < val.size(); ++i)
            sum += val[i];
        
        return sum / val.size();
    }

    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return vector<double>();
        vector<vector<int>> val;
        deque<TreeNode*> de;
        de.push_back(root);

        while (!de.empty())
        {
            int size = de.size();
            vector<int> tmp;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = de.front();
                de.pop_front();
                tmp.push_back(cur->val);
                if (cur->left) de.push_back(cur->left);
                if (cur->right) de.push_back(cur->right);
            }
            val.push_back(tmp);
        }
        vector<double> res(val.size(), 0);
        for (int i = 0; i < val.size(); ++i)
            res[i] = average(val[i]);


        return res;
    }
};
// @lc code=end

