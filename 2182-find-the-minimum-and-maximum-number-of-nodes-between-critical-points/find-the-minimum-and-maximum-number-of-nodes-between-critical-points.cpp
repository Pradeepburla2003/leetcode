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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        int pos=1;
        while(head->next && head->next->next){
            int t1=head->val;
            int t2=head->next->val;
            int t3=head->next->next->val;
            if(t1>t2 && t2<t3){
                ans.push_back(pos);
            }
            else if(t1<t2 && t2>t3){
                ans.push_back(pos);
            }
            pos++;
            head=head->next;
        }
        if(ans.size()<2){
            return {-1,-1};
        }
        int mini=INT_MAX,n=ans.size();
        for(int i=0;i<ans.size()-1;i++){
            mini=min(mini,ans[i+1]-ans[i]);
            cout<<ans[i]<<" ";
        }
        return {mini,ans[n-1]-ans[0]};
    }
};