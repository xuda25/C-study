/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    //    1    2    3    4    5    1
    //                      
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;
            
        int size = 1;
        ListNode* cur = head;
        while (cur->next)
        {
            ++size;
            cur = cur->next;
        }
        // 切割点
        int n = k % size;
        if (n == 0)
            return head;

        // 组成环
        cur->next = head;
        //找切割点前个节点
        ListNode* pre = head;
        int index = size - n - 1;

        while (index-- > 0)
            pre = pre->next;
        
        head = pre->next;
        pre->next = nullptr;

        return head;
    }
};
// @lc code=end

