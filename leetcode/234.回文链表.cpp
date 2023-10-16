/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
// 使用额外空间

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> data;
//         ListNode* cur = head;
//         while (cur != nullptr)
//         {
//             data.push_back(cur->val);
//             cur = cur->next;
//         }

//         int size = data.size();

//         for (int i = 0, j = size-1; i <= j; ++i, --j)
//         {
//             if (data[i] != data[j])
//                 return false;
//         }
//         return true;
//     }
// };


class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tem;
        while (cur)
        {
            tem = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tem;
        }

        return pre;

    }

    bool isPalindrome(ListNode* head) {
        if (head && !head->next)
            return true;
        // 找分界
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 找到了 第一段 head开头 第二段 slow开头
        pre->next = nullptr;
         
        // 反转 第二段
        slow = reverseList(slow);

        // 比较两个

        while (head)
        {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end

