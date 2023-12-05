/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    // 1        2       4
    //cur1      next1
    // 1        3       4
    //list2     next2

    //if (cur1->val <= list2->val)  cur1->next = list2  
    //              >              cur1 = next1
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }

        if (list1)
            cur->next = list1;
        if (list2)
            cur->next = list2;

        return dummy->next;
    }
};
// O(m+n)
// O(1)  节点都是原本就有的 


// @lc code=end

