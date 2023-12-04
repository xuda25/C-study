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

// 非递归
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;
//         ListNode* cur = dummy;
//         while (cur->next != nullptr && cur->next->next != nullptr)
//         {
//             ListNode* tem1 = cur->next;
//             ListNode* tem2 = cur->next->next->next;

//             cur->next = cur->next->next;
//             cur->next->next = tem1;
//             cur->next->next->next = tem2;

//             cur = cur->next->next;
//         }

//         return dummy->next;
//     }
// };

//自写递归
// class Solution {
// public:
//     // 递归的最小单元: 交换两个单元 cur next
//     // 返回条件: head为空 或者 next为空
//     // 返回值:  next
//     ListNode* swapPairs(ListNode* head) {
//         if (head == nullptr || head->next == nullptr)
//             return head;
        
//         ListNode* next = head->next;
//         head->next = swapPairs(head->next->next);
//         next->next = head;

//         return next;
//     }
// };

// 自写模拟
// 模拟
class Solution {
public:
//    dummy       1       2       3       4
//     pre       cur     next    
//    pre->next = next   cur->next = next->next   next->next = cur
//    dummy       2       1       3       4
//    pre = cur    cur = pre->next  next = cur->next
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        while (pre->next && pre->next->next)
        {
            ListNode* cur = pre->next;
            ListNode* next = cur->next;

            pre->next = next;
            cur->next = next->next;
            next->next = cur;

            pre = cur;
        }

        return dummy->next;
    }
};
// @lc code=end

