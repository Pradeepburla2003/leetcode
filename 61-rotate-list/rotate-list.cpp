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
        if(!head or !head->next) return head;
        int size=0;
        ListNode* temp=head;
        ListNode* ans=new ListNode();
        ListNode* res=ans;
        ListNode* dum=NULL;
        while(head && head->next){
            size+=2;
            head=head->next->next;
        }
        if(head) size+=1;
        head=temp;
        int rev=size-(k%size);
        while(rev>1){
            head=head->next;
            rev--;
        }
        ans->next=head->next;

        while(ans->next){
            ans=ans->next;
        }
        head->next=dum;
        ans->next=temp;
        return res->next;
        return temp;
    }
};