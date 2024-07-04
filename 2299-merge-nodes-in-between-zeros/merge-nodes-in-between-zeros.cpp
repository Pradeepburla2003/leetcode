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
    ListNode* mergeNodes(ListNode* head) {
        int ans=0;
        ListNode* res=new ListNode();
        ListNode* dup=res;
        while(head){
            if(head->val==0){
                if(ans!=0){
                    res->next=new ListNode(ans);
                    ans=0;
                    res=res->next;
                }
            }
            else{
                ans+=head->val;
            }
            head=head->next;

        }
         if(ans!=0){
            res->next=new ListNode(ans);
            ans=0;
            res=res->next;
        }
        return dup->next;
    }
};