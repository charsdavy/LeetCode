//
//  Solution.cpp
//  LeetCode-C++
//
//  Created by dengw on 2020/11/18.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution
{
public:    
    ListNode* reverseList(ListNode* head);
};

using namespace std;

/**
 206. Reverse Linked List
 迭代
 Reverse a singly linked list.

 Example:

 Input: 1->2->3->4->5->NULL
 Output: 5->4->3->2->1->NULL
 Follow up:

 A linked list can be reversed either iteratively or recursively. Could you implement both?
 */
ListNode* Solution::reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *cur = head;
    
    while (cur != NULL) {
        ListNode *nextTemp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextTemp;
    }
    return prev;
}

/**
 206. Reverse Linked List
 递归
 */
ListNode* Solution::reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}

/**
 206. Reverse Linked List
 双指针
 */
ListNode* Solution::reverseList(ListNode* head) {
    ListNode *cur = NULL, *prev = head;
    while (prev != NULL) {
        ListNode *t = prev->next;
        prev->next = cur;
        cur = prev;
        prev = t;
    }
    return cur;
}