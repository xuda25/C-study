/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// //  nullptr       1       2       3       4       5
// //                                             pre       cur     next
// //    cur->next = pre  pre = cur  cur = next
//     ListNode* reverseList(ListNode* head) {
//         ListNode* pre = nullptr;
//         ListNode* cur = head;
//         while (cur)
//         {
//             ListNode* next = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = next;
//         }
        
//         return pre;
//     }
// };

// 递归
class Solution {
public:
//  最小层:  交换两个节点指向
//   返回值  最后一个节点
//  返回条件  后面没节点了
//    1       2       3       4       5
//

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* newH = reverseList(head->next);  // 找到最后一个节点

        head->next->next = head;
        head->next = nullptr;

        return newH;
    }
};
// @lc code=end

