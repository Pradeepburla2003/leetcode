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
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int length1=0,length2=0;
        while(temp1 && temp1->next){
            length1+=2;
            temp1=temp1->next->next;
        }
        if(temp1) length1+=1;
        while(temp2 && temp2->next){
            length2+=2;
            temp2=temp2->next->next;
        }
        if(temp2) length2+=1;
        if(length1>length2){
            while(length1-length2>0){
                headA=headA->next;
                length1--;
            }
        }
        else{
            while(length2-length1>0){
                headB=headB->next;
                length2--;
            }
        }
        while(headA && headB && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};