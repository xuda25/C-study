/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
// 层序遍历到那一层  开始新增

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
        {
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }

        queue<TreeNode*> qu;  //存要在下面新增节点的节点
        qu.push(root);
        while (--depth > 1)
        {   
            int size = qu.size();
            
            for (int i = 0; i < size; ++i)
            {
                TreeNode* cur = qu.front();
                qu.pop();
                if (cur->left) qu.push(cur->left);
                if (cur->right) qu.push(cur->right);
            }
        }



        // 开始转换
        while (!qu.empty())
        {
            TreeNode* cur = qu.front();
            cout << cur->val << " ";
            qu.pop();
            TreeNode* l = cur->left;
            TreeNode* r = cur->right;
            cur->left = new TreeNode(val);
            cur->left->left = l;
            cur->right = new TreeNode(val);
            cur->right->right = r;
        }

        return root;
    }
};

//class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) return nullptr;
        if (depth == 1)
            return new TreeNode(val, root,nullptr);
        if (depth == 2)
        {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
        }
        else
        {
            root->left = addOneRow(root->left, val, depth-1);
            root->right = addOneRow(root->right, val, depth-1);
        }
        
        return root;
    }
};
// @lc code=end

