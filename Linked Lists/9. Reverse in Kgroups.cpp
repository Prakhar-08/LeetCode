// Leetcode - 25
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        
        while (curr != NULL && count != k) { 
            curr = curr->next;
            count++;
        }
        
        if (count == k) { 
            curr = reverseKGroup(curr, k);
        
            while (count != 0) { 
                ListNode* tmp = head->next; 
                head->next = curr; 
                curr = head;
                head = tmp; 
                count--;
            }
            
            head = curr;
            
        }
        return head;
    }
};