/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// 两个队列
// 耗空间
// class Solution {
// public:
//     Node* connect(Node* root) {
//         if (!root)
//             return nullptr;

//         queue<Node*> que1;
//         queue<Node*> que2;

//         que1.push(root);

//         while (!que1.empty())
//         {
//             Node* cur = que1.front();
//             que1.pop();
//             if (!que1.empty())
//                 cur->next = que1.front();
//             else
//                 cur->next = nullptr;          
//             if (cur->left)
//             {
//                 que2.push(cur->left);
//                 que2.push(cur->right);
//             }
//             if (que1.empty())
//             {
//                 while (!que2.empty())
//                 {
//                     que1.push(que2.front());
//                     que2.pop();
//                 }
//             }
//         }
//         return root;
//     }
// };



// 递归
// class Solution {
// public:
//     void travel(Node* root)
//     {
//         if (!root)
//             return;

//         // 左
//         if (root->left)
//             root->left->next = root->right;
//         // 右
//         if (root->right)
//             if (root->next)
//                 root->right->next = root->next->left;
//             else
//                 root->right->next = nullptr;

//         travel(root->left);
//         travel(root->right);
//     }

//     Node* connect(Node* root) {
//         if (!root)
//             return nullptr;
//         travel(root);
//         return root;
//     }
// };


// 广度优先遍历
class Solution {
public:
    void travel(Node* root)
    {
        if (!root)
            return;

        // 左
        if (root->left)
            root->left->next = root->right;
        // 右
        if (root->right)
            if (root->next)
                root->right->next = root->next->left;
            else
                root->right->next = nullptr;

        travel(root->left);
        travel(root->right);
    }

    Node* connect(Node* root) {
        if (!root)
            return nullptr;

        queue<Node*> que;
        que.push(root);

        while (!que.empty())
        {
            int size = que.size();

            for (int i = 0; i < size; ++i)
            {
                Node* cur = que.front();
                que.pop();
                if (i != size - 1)
                    cur->next = que.front();
                else
                    cur->next = nullptr;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        
        return root;
    }
};
// @lc code=end

