/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* tem1 = cur->next;
            ListNode* tem2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tem1;
            cur->next->next->next = tem2;

            cur = cur->next->next;
        }

        return dummy->next;
    }
};
// @lc code=end

