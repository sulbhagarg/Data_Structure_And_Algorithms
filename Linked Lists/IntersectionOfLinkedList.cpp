// Write a program to find the node at which the intersection of two singly linked lists begins.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        if(!tempA || !tempB)
            return NULL;
        while(tempA && tempB && tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
            if(tempA==tempB)
                return tempA;
            if(tempA==NULL)
                tempA=headB;
            if(tempB==NULL)
                tempB=headA;
        }
        return tempA;
    }
};
