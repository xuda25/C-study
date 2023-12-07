/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
// 用额外空间
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> s;
//         ListNode* cur = head;
//         while (cur)
//         {   
//             if (!s.count(cur))
//                 s.insert(cur);
//             else
//                 return cur;
//             cur = cur->next;
//         }
//         return nullptr;
//     }   
// };

// 不用额外空间
class Solution {
public:
//  3       2       0       4
//  ------------------>
//     a      |-------|
//            |       |  
//            |       | b
//            |       | 
//       c    |       | 
//            --------v
//                
// v处相遇  快慢相遇前 快已经走了至少一圈了 
//    k(b+c) + b + a = 2a + 2b
//      a = (k-1)(b+c) + c  
//     起点和交点同时出发相遇就是答案
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast)
        {
            slow = slow->next;
            if (!fast->next)
                return nullptr;
            fast = fast->next->next;

            if (slow == fast)
            {
                ListNode* pre = head;
                while (slow != pre)
                {
                    pre = pre->next;
                    slow = slow->next;
                }

                return pre;
            }
        }

        return nullptr;
    }   
};
// @lc code=end

