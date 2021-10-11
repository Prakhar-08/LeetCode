// Leetcode - 148
// Given the head of a linked list, return the list after sorting it in ascending order.

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
    ListNode* midPoint(ListNode* head) {
    if(head == NULL)
        return head;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast->next != NULL and fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* merge(ListNode* head1, ListNode* head2)
{
    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1;
    
    ListNode* fhead;
    ListNode* ftail;
    
    if(head1->val <= head2->val) {
        fhead = head1;
        ftail = head1;
        head1 = head1->next;
    }
    
    else if(head2->val < head1->val) {
        fhead = head2;
        ftail = head2;
        head2 = head2->next;
    }
    
    
    while(head1 != NULL and head2 != NULL) {
        if(head1->val <= head2->val) {
            ftail->next = head1;
            ftail = ftail->next;
            head1 = head1->next;
        }
        
        else if(head2->val < head1->val) {
            ftail->next = head2;
            ftail = ftail->next;
            head2 = head2->next;
        }
    }
    
    if(head1 == NULL) {
        ftail->next = head2;
    }
    
    else if(head2 == NULL) {
        ftail->next = head1;
    }
    
    return fhead;
}


ListNode *sortList(ListNode *head)
{
	if(head == NULL || head->next == NULL)
        return head;
    
    ListNode* mid = midPoint(head);
    
    ListNode* half1 = head;
    ListNode* half2 = mid->next;
    mid->next = NULL;
    
    half1 = sortList(half1);
    half2 = sortList(half2);
    ListNode* finalHead = merge(half1, half2);
    
    return finalHead;
}
};