/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
// 算数字
// class Solution {
// public:
// //  dummy       1       2       3       4       5       null
// //             pre       cur     next
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int size = 0;
//         ListNode* dummy = new ListNode(0, head);
//         ListNode* pre = dummy;
//         ListNode* cur = head;
//         while (cur)
//         {
//             cur = cur->next;
//             ++size;
//         }

//         int k = size - n;
//         cur = head;
//         ListNode* next = cur->next;
//         while (k-- > 0)
//         {
//             pre = cur;
//             cur = next;
//             next = cur->next;
//         }
//         pre->next = next;
//         delete cur;
//         return dummy->next;
//     }
// };
// O(n)
// O(1)


// 利用栈 先进后出
// class Solution {
// public:
// //  dummy       1       2       3       4       5       null
// //                                                     cur

// //st  dummy     1       2       3       4       5     
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* dummy = new ListNode(0, head);
//         ListNode* cur = dummy;
//         stack<ListNode*> st;
//         while (cur)
//         {
//             st.push(cur);
//             cur = cur->next;
//         }

//         ListNode* top;
//         for (int i = n; i > 0; --i)
//         {
//             top = st.top();
//             st.pop();
//         }
//         st.top()->next = top->next;
//         delete top;

//         return dummy->next;
//     }
// };
// O(n)
// O(n)

//  双指针   一快一慢  相差n   快到尾 慢结果
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

// @lc code=end

