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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(-1);
        ListNode* dummy=ans;
        int carry=0,add;
        while(l1 && l2){
            add=l1->val+l2->val+carry;
            if(add>=10) carry=1;
            else carry=0;
            dummy->next=new ListNode(add%10);
            dummy=dummy->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            add=l1->val+carry;
            if(add>=10) carry=1;
            else carry=0;
            dummy->next=new ListNode(add%10);
            dummy=dummy->next;
            l1=l1->next;
        }
        while(l2){
            add=l2->val+carry;
            if(add>=10) carry=1;
            else carry=0;
            dummy->next=new ListNode(add%10);
            dummy=dummy->next;
            l2=l2->next;
        }
        if(carry){
            dummy->next=new ListNode(1);
            dummy=dummy->next;
        }
        return ans->next;
    }
};