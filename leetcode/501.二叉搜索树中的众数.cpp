/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
// 递归
// class Solution {
// public:
//     int times = 0;
//     int time = 0;
//     TreeNode* pre = nullptr;
//     vector<int> ans;
//     void travel(TreeNode* root)
//     {
//         if (!root) return;
        
//         travel(root->left);

//         if (!pre)
//             time = 1;
//         else if (pre && root->val == pre->val)
//             ++time;
//         else if (pre && root->val != pre->val)   
//             time = 1;

//         pre = root;

//         if (time == times)
//             ans.push_back(root->val);
        
        
//         if (time > times)
//         {
//             ans.clear();
//             times = time;
//             ans.push_back(root->val);
//         }

//         travel(root->right);

//         return;
//     } 
//     vector<int> findMode(TreeNode* root) {
//         travel(root);
//         return ans;
//     }
// };

//迭代

class Solution {
public:
    int times = 0;
    int time = 0;
    TreeNode* pre = nullptr;
    vector<int> ans;

    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();

                if (!pre)
                    time = 1;
                else if (cur->val == pre->val)
                    ++time;
                else if (cur->val != pre->val)
                    time = 1;

                pre = cur;

                if (time == times)
                    ans.push_back(cur->val);
                if (time > times)
                {
                    times = time;
                    ans.clear();
                    ans.push_back(cur->val);
                }

                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end

