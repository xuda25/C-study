/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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

class Solution {
public:
//   1      2       3       4

    Node* connect(Node* root) {
        if (!root) return NULL;
        queue<Node*> qu;
        qu.push(root);

        while (!qu.empty())
        {
            int size = qu.size();

            for (int i = 0; i < size; ++i)
            {
                Node* cur = qu.front();
                qu.pop();
                if (cur->left) qu.push(cur->left);
                if (cur->right) qu.push(cur->right);
                if (i != size - 1)
                    cur->next = qu.front();
                else
                    break;
            }
        }
        return root;
    }
        
};

// 递归

// 用一个vector维护
// depth == size 说明 这是最左边的元素  接下一个 vec[dep]更新为下一个
class Solution {
public:
    vector<Node*> tmp;
    void dfs(Node* root, int depth)
    {
        if (!root) return;
        if (depth == tmp.size())
            tmp.push_back(root);
        else
        {
            tmp[depth]->next = root;
            tmp[depth] = root;
        }
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }

    Node* connect(Node* root) {
        dfs(root, 0);
        return root;
    }
};
// @lc code=end

