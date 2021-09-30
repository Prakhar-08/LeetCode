// Leetcode - 61. Rotate List
// Given the head of a linked list, rotate the list to the right by k places.

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
    int length(ListNode* head) {
        if(head == NULL)
            return 0;
        
        return 1 + length(head->next);
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* tail = head;
        int len = length(head);
        
        while(tail->next != NULL)
            tail = tail->next;
        
        tail->next = head;   //Connected circulary
        
        int rounds = k%len;
        for(int i=0; i<len-rounds; i++)
            tail = tail->next;
        
        ListNode* newHead = tail->next;
        tail->next = NULL;
        
        return newHead;
    }
};