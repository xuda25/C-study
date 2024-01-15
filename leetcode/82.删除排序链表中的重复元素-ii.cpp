/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
//my
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
//      dummy    1   1   1   2   3
//              pre         cur
//      dummy   1   2   3   3   4   4   5

//      dummmy  1   1
//                    
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* dummycur = dummy;
        ListNode* pre = head;
        ListNode* cur = head->next;

        while (cur)
        {
            if (pre->val == cur->val)
            {
                while (cur && cur->val == pre->val)
                    cur = cur->next;
                pre = cur;
                if (cur)
                    cur = cur->next;
            }
            else
            {   
                dummycur->next = pre;
                dummycur = dummycur->next;
                pre = cur;
                cur = cur->next;
            }
        }
        dummycur->next = pre;
        return dummy->next;
    }
};


// ans
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
//      dummy   1   2   3   3   4   4   5
//     
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;

        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x)
                    cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }

        return dummy->next;
    }
};
// @lc code=end

