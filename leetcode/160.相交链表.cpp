/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;

        ListNode*cur1 = headA;

        while (cur1)
        {
            set.emplace(cur1);
            cur1 = cur1->next;
        }

        ListNode* cur2 = headB;

        while (cur2)
        {
            if (set.count(cur2))
                return cur2;
            cur2 = cur2->next;
        }

        return nullptr;
    }
};
// @lc code=end

