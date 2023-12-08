/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// bfs
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> res;
        deque<Node*> de;
        de.push_back(root);

        while (!de.empty())
        {
            vector<int> tmp;
            int size = de.size();

            for (int i = 0; i < size; ++i)
            {
                Node* cur = de.front();
                de.pop_front();
                int s = cur->children.size();
                for (int j = 0; j < s; ++j)
                {
                    de.push_back(cur->children[j]);
                }
                tmp.push_back(cur->val);
            }
            res.push_back(tmp);
        }

        return res;
    }
};
// O(n)
// O(n)

// dfs
class Solution {
public:
    void dfs(vector<vector<int>>& res, Node* root, int depth)
    {
        if (!root) return;
        if (res.size() == depth)
            res.push_back(vector<int>());
        res[depth].push_back(root->val);
        int size = root->children.size();
        for (int i = 0; i < size; ++i)
        {
            dfs(res, root->children[i], depth + 1);
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        int depth = 0;
        dfs(res, root, depth);
        return res;
    }
};
// O(n)
// O(n)
// @lc code=end

