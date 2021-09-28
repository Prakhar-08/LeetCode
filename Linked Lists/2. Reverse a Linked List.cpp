// Leetcode - 206
// Given the head of a singly linked list, reverse the list, and return the reversed list.

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
    //Recursive Approach
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* p = head->next;
        head->next = NULL;
        
        ListNode* newNode = reverseList(p);
 
        p->next = head;
 
        return newNode;
    }
    

    // Iterative Approach
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode* p = NULL;
        ListNode* q = NULL;
        ListNode* temp = head;
        
        while(temp != NULL) {
            p = temp->next;
            temp->next = q;
            
            q = temp;
            temp = p;
        }
        
        return q;
    }
};