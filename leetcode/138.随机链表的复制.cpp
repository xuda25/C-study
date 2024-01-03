/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// 链表存进 unordered_map<int, Node*>里面
// 深拷贝 按顺序链接
// random链接
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        unordered_map<int, Node*> old;
        unordered_map<Node*, int> oldI;
        unordered_map<int, Node*> n;
        Node* cur = head;
        int index = 0;
        while (cur)
        {
            old[index] = cur;
            oldI[cur] = index++;
            cur = cur->next;
        }
        Node* nHead = new Node(head->val);
        n[0] = nHead;
        cur = nHead;
        for (int i = 1; i < old.size(); ++i)
        {
            Node* nN = new Node(old[i]->val);
            cur->next = nN;
            cur = cur->next;
            n[i] = nN;
        }

        for (int i = 0; i < old.size(); ++i)
        {
            Node* ran = old[i]->random;
            if (!ran) continue;
            int index = oldI[ran];

            n[i]->random = n[index];
        }

        return nHead;
    }
};


// 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;
        Node* cur = head;

        while (cur)
        {
            Node* n = new Node(cur->val);
            mp[cur] = n;
            cur = cur->next;
        }
        cur = head;
        while(cur)
        {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }

        return mp[head];
    }
};
// @lc code=end

