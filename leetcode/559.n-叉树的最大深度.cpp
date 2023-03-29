/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 鍙夋爲鐨勬渶澶ф繁搴�
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
// 递归
// class Solution {
// public:
//     int result;
//     int depth(Node* root, int dep)
//     {   

//         if (root == nullptr) return dep;

//         dep += 1;
//         for (auto node : root->children)
//         {   
//             if (node)
//             {
//                depth(node, dep); 
//             }
//         }
//         result = dep> result ? dep : result;
//         return result;
//     }

//     int maxDepth(Node* root) {
//         result = 0;
//         return depth(root, 0);
//     }
// };


// 迭代

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        int dep = 0;
        if (root)
            que.push(root);
        
        while (!que.empty())
        {
            int size = que.size();
            ++dep;
            for (int i = 0; i < size; ++i)
            {
                Node* cur = que.front();
                que.pop();
                for (auto node : cur->children)
                    if (node)
                        que.push(node);
            }
        }
        return dep;
    }
};
// @lc code=end

