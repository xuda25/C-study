/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
//  1       2       3       4                   5
//leftL   left         left+(right - left)    rightR

//   null       2       3       4       
//   pre     cur     next
// cur->next = pre   pre = cur   cur = next
    void reverse(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

    //         dummy     3      5
    //          leftL
    //                       rightN
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 因为头节点可能发生变化 设置一个dummy
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* leftL = dummy;
        int i = left;
        while (--i > 0)
            leftL = leftL->next; // 找到left前一个节点
    
        int t = right - left;
        ListNode* rightN = leftL;
        while (t-- >= 0)
            rightN = rightN->next;  //找到右边节点
    
        ListNode* leftN = leftL->next;
        ListNode* rightR = rightN->next;

        //切断
        leftL->next = nullptr;
        rightN->next = nullptr;

        // 反转中间
        reverse(leftN);
        
        //拼接
        leftL->next = rightN;
        leftN->next = rightR;
        
        return dummy->next;  //如果第一个元素变了 就不能返回head   要用dummy
    }
};
// @lc code=end

