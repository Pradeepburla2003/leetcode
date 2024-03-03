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
        ListNode* temp=head;
        ListNode* temp2=head;
        ListNode* temp3=head;
        int c=0;
        while(temp && temp->next)
        {
            c+=2;
            temp2=temp2->next;
            temp=temp->next->next;
        }
        c+=(temp!=NULL);
        if(n<(c/2))
        {
            if(c%2==1)
            {
                c+=1;
            }
            c=(c/2)-n;
            while(temp2)
            {
                c-=1;
                if(c==0)
                {
                    temp2->next=temp2->next->next;
                    break;
                }
                temp2=temp2->next;
            }
        }
        else if(c==n)
        {
            return head->next;
        }
        else
        {
            c=c-n;
            while(temp3)
            {
                c-=1;
                if(c==0)
                {
                    temp3->next=temp3->next->next;
                    break;
                }
                temp3=temp3->next;
                
            }
        }
        return head;
    }
};