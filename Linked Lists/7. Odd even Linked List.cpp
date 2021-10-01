// Leetcode - 328

// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.





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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode* temp = head;
        
        ListNode* oddHead = NULL;
        ListNode* evenHead = NULL;
        ListNode* oddTail = NULL;
        ListNode* evenTail = NULL;
        
        int i=1;
        while(temp != NULL) {
            if(i % 2 != 0) {
                if(oddHead == NULL) {
                    oddHead = temp;
                    oddTail = temp;
                } else {
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
            } else {
                if(evenHead == NULL) {
                    evenHead = temp;
                    evenTail = temp;
                } else {
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
            }
            
            temp = temp->next;
            i++;
        }
        
        
        if(oddHead == NULL) {
            evenTail->next = NULL;
            return evenHead;
        }
        else if(evenHead == NULL) {
            oddTail->next = NULL;
            return oddHead;
        }
        else {
            evenTail->next = NULL;
            oddTail->next = evenHead;
            return oddHead;
        }
    }
};