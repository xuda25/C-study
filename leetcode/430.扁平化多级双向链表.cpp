/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;

        while (cur && !cur->child)
        {
            cur = cur->next;
        }
        if (!cur)
            return head;
        Node* next = cur->next;
        cur->next = flatten(cur->child);
        cur->child = nullptr;
        while (cur->next)
            cur = cur->next;
        cur->next = next;
        return head;
    }
};
// @lc code=end

