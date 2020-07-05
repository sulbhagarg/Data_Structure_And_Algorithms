/* You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* root = NULL;
        ListNode* node = NULL;
        ListNode* result = node;
        int flag=0;
        int x;
        x = l1->val + l2->val + flag;
        node = new ListNode(x);
        if(x>=10){
            node->val=node->val%10;
            flag=x/10;
        }
        root = node;
        node = node->next;
        l1=l1->next;
        l2=l2->next;
        ListNode* prev=root;
        while(l1!=NULL || l2!=NULL || flag)
        {
            int x=flag;
            if(l1){
                x+=l1->val;
                l1=l1->next;
            }
            if(l2){
                x+=l2->val;
                l2=l2->next;
            }
            node = new ListNode(x);
            node->val=node->val%10;
            flag=x/10;
            prev->next=node;
            prev=prev->next;
            node = node->next;
        }
        return root;
        
    }
};
