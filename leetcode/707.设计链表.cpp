/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct Node
    {   
        Node() : val(0), next(nullptr) {}
        Node(int v) : val(v), next(nullptr) {}
        Node(int v, Node* n) : val(v), next(n) {}

        int val;
        Node* next;
    };


    MyLinkedList() {
        dummy = new Node();
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        Node* cur = dummy->next;
        while (index-- > 0)
            cur = cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* next = dummy->next;
        Node* n = new Node(val, next);
        dummy->next = n;
        ++size;
    }
    
    void addAtTail(int val) {
        Node* cur = dummy;
        while (cur->next)
            cur = cur->next;
        cur->next = new Node(val);
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }    
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        if (index > size) return;
        if (index < 0) index = 0;
        Node* cur = dummy;
        while (index-- > 0)
            cur = cur->next;
        Node* n = new Node(val, cur->next);
        cur->next = n;
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* cur = dummy;
        while (index-- > 0)
            cur = cur->next;
        Node* de = cur->next;
        cur->next = de->next;
        delete de;
        --size;
    }

    Node* dummy;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

