// Leetcode - 234
// Given the head of a singly linked list, return true if it is a palindrome.

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        
        while(slow != NULL) {
            if(head->val != slow->val)
                return false;
            
            head=head->next;
            slow=slow->next;
        }
        
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* p = NULL;
        ListNode* q = NULL;
        
        while(head != NULL) {
            p = head->next;
            head->next = q;
            
            q = head;
            head = p;
        }
        
        return q;
    }
};