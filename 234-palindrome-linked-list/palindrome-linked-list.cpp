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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp1;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        while(slow){
            temp1=slow;
            slow=slow->next;
            temp1->next=temp;
            temp=temp1;
        }
        while(temp && head){
            if(head->val!=temp->val) return false;
            head=head->next;
            temp=temp->next;
        }
        return true;
    }
};