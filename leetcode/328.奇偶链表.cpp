/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* oddH = odd;
        ListNode* evenH = even;
        int i = 1;
        while (head)
        {
            if (i % 2 != 0)
            {
                odd->next = head;
                odd = odd->next;
            }
            else
            {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            ++i;
        }
        even->next = nullptr;
        odd->next = evenH->next;

        return oddH->next;
    }
};
// @lc code=end

