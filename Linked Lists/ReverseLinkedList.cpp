// Reverse a singly linked list.

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
 
 // A simple 3 ptr approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* p=head;
        ListNode* q=p->next;
        ListNode* r=q;
        p->next=NULL;
        while(r!=NULL){
            r = q->next;
            q->next=p;
            p=q;
            q=r;
        }
        return p;
    }
};
