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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* dummy=head;
        while(head && head->next){
            n+=2;
            head=head->next->next;
        }
        if(head) n+=1;
        head=dummy;
        n=n/k;
        ListNode* ans=new ListNode();
        ListNode* res=ans;
        while(n){
            int i=0;
            ListNode* rev=NULL;
            ListNode* temp;
            while(i<k and head){
                temp=head->next;
                head->next=rev;
                rev=head;
                head=temp;
                i++;
            }
            ans->next=rev;
            while(ans->next){
                ans=ans->next;
            }
            n--;
        }
        if(head) ans->next=head;
        return res->next;
    }
};