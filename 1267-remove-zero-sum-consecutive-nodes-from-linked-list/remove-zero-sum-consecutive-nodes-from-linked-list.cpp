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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*>mp;
        int sum=0;
        ListNode* ans=new ListNode();
        ans->next=head;
        mp[sum]=ans;
        while(head){
            sum+=head->val;
            if(mp.find(sum)!=mp.end()){
                ListNode* prev=mp[sum];
                ListNode* start=mp[sum]->next;
                int removesum=sum;
                while(start!=head){
                    removesum+=start->val;
                    start=start->next;
                    mp.erase(removesum);
                }
                prev->next=head->next;
            }
            else{
                mp[sum]=head;
            }
            
            head=head->next;
        }
        return ans->next;
    }
};