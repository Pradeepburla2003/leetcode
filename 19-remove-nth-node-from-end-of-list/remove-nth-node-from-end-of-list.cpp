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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode* temp=head;
        while(temp && temp->next){
            length+=2;
            temp=temp->next->next;
        }
        if(temp) length+=1;
        if(length==n) return head->next;
        temp=head;
        for(int i=0;i<length-n-1;i++){
            temp=temp->next;
        }
        ListNode* temp2=temp->next;
        temp->next=temp2->next;
        return head;
    }
};