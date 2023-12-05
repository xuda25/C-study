/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        cur->next = l1 ? l1 : l2;

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)  return nullptr;
        if (lists.size() == 1)  return lists[0];
        ListNode* cur = lists[0];

        for (int i = 1; i < lists.size(); ++i)
        {   
            if (!lists[i])
                continue;
            cur = merge(cur, lists[i]);
        }

        return cur;
    }
};

// 优先队列 归并排序
class Solution {
public:
    struct Node
    {
        int val;
        ListNode* ptr;
        Node(int val, ListNode* p) : val(val), ptr(p) {}
        bool operator< (const Node& n) const
        {
            return val > n.val;
        }
    };

    priority_queue<Node> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto l : lists)
            if (l)
                q.push(Node(l->val, l));

        ListNode* head = new ListNode(0, nullptr);
        ListNode* cur = head;
        
        while (!q.empty())
        {
            auto f = q.top();
            q.pop();
            cur->next = f.ptr;
            cur = cur->next;
            if (f.ptr->next)
                q.push(Node(f.ptr->next->val, f.ptr->next));
        }

        return head->next;
    }
};
// @lc code=end

