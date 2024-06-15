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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int flag=0;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=1;
                break;
            }
        }
        if(flag==0) return NULL;
        while(slow->val!=head->val){
            slow=slow->next;
            head=head->next;
        }
        return slow;
    }
};