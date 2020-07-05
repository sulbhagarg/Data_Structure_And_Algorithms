// Given a singly linked list, determine if it is a palindrome.

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
        if(!head || !head->next)
            return true;
        
        // find Middle
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast && fast->next==NULL)
            slow=slow->next;
        
        // Reverse
        ListNode* p=head;
        ListNode* q=p->next;
        ListNode* r=q;
        p->next=slow;
        while(r!=slow){
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        if(fast && fast->next==NULL)
            p=p->next;
        
        // Check the equality
        while(slow){
            if(p->val!=slow->val)
                return false;
            p=p->next;
            slow=slow->next;
        }
        return true;
    }
};
