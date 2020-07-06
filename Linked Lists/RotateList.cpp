// Given a linked list, rotate the list to the right by k places, where k is non-negative.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int len=1;
        ListNode* temp=head;
        ListNode* prev;
        while(temp->next){
            prev=temp;
            temp=temp->next;
            len++;
        }
        k=k%len;
        while(k){
            k--;
            temp->next=head;
            head=temp;
            prev->next=NULL;
            temp=prev;
            prev=head;
            while(prev->next!=temp){
                if(prev->next==temp)
                    break;
                prev=prev->next;
            }
        }
        return head;
    }
};

// MORE OPTIMISED APPROACH (But it gave me same runtime :(. )
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int len=1;
        ListNode* temp=head;
        ListNode* prev;
        while(temp->next){
            temp=temp->next;
            len++;
        }
        temp->next=head;
        k = len - k%len;
        while(k--)
            temp=temp->next;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
