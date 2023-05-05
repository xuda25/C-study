/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 浜屽弶鏍戠殑鍓嶅簭閬嶅巻
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
#include <vector>
#include <stack>

using namespace std;

/**递归方法
 
class Solution {
public:

    void preOrder(TreeNode* root, vector<int> &ans)
    {
        if (root == nullptr) return;
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        preOrder(root, ans);
        return ans;
    }
};

*/

// 迭代方法
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode *root)
//     {
//         stack<TreeNode*> st;
//         vector<int> ans;
        
//         if (root == nullptr)
//             return vector<int>();
        
//         st.push(root);

//         while (!st.empty())
//         {
//             ans.push_back(st.top()->val);
//             TreeNode *tem = st.top();
//             st.pop();
//             if (tem->right != nullptr) st.push(tem->right);
//             if (tem->left != nullptr) st.push(tem->left);
//         }
//         return ans;
//     }
// };


//统一的迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode *cur = root;
        if (cur != nullptr)
            st.push(cur);
        while (!st.empty())
        {   
            TreeNode *top = st.top();
            if (top != nullptr)
            {
                st.pop();

                if (top->right) st.push(top->right);

                if (top->left) st.push(top->left);

                st.push(top);
                st.push(nullptr);

            }
            else
            {
                st.pop();
                ans.push_back(st.top()->val);
                st.pop();
            }
        }
        return ans;
        
    }
    
};
// @lc code=end

