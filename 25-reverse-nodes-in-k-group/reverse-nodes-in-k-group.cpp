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
        int size=0,start=0;
        ListNode* temp2=head;
        ListNode* ans=new ListNode();
        ListNode* res=ans;
        while(head && head->next){
            size+=2;
            head=head->next->next;
        }
        if(head) size+=1;
        head=temp2;
        int c=0;
        while((start+k)<=size){
            ListNode* temp=NULL;
            ListNode* temp1;
            int count=0;
            while(count<k && head){
                temp1=head;
                head=head->next;
                temp1->next=temp;
                temp=temp1;
                count++;
            }
            ans->next=temp;
            while(count){
                ans=ans->next;
                count--;
            }
            // cout<<start<<" ";
            // if(c==3) return res->next;
            start+=k;
            c++;
        }
        ans->next=head;
        return res->next;
    }
};