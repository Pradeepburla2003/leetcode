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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int c=0;
        while(temp && temp->next)
        {
            c+=1;
            temp=temp->next->next;
        }
        while(c>0)
        {
            head=head->next;
            c-=1;
            if(c==0)
            {
                break;
            }
        }
        return head;
    }
};