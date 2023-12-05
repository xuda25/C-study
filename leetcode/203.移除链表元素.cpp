/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
// class Solution {
// public:
// //  dummy        1       2       6       3       4       5       6      null
// //                                                      pre      cur     next
// //  if (cur != val)  pre = cur  cur = next  next = cur->next
// //  if (cur == val)  pre->next = next  delete cur  cur = next  (next = cur->next)
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode* dummy = new ListNode(0, head);
//         ListNode* pre = dummy;
//         ListNode* cur = head;

//         while (cur)
//         {
//             ListNode* next = cur->next;
//             if (cur->val != val)
//             {
//                 pre = cur;
//                 cur = next;
//             }
//             else
//             {
//                 pre->next = next;
//                 delete cur;
//                 cur = next;
//             }
//         }
//         return dummy->next;
//     }
// };
// O(n)
// O(1)

//递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;

        head->next = removeElements(head->next, val);
        if (head->val == val)
            return head->next;
        
        return head;
    }
};
// O(n)
// O(n)
// @lc code=end

