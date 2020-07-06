/* Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions. */

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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(INT_MIN);
        ListNode dummy2(INT_MIN);
        ListNode* head1 = &dummy1;
        ListNode* head2 = &dummy2;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode* temp = head;
        while(temp){
            if(temp->val<x){
                temp1->next=new ListNode(temp->val);
                temp1=temp1->next;
            }
            else{
                temp2->next=new ListNode(temp->val);
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        if(head2)
            temp1->next=head2->next;
        return head1->next;
    }
};
