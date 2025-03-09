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
    ListNode* merge(ListNode* l1,ListNode* l2){
       if(!l1) return l2;
       if(!l2) return l1;
       if(l1->val<=l2->val){
        l1->next=merge(l1->next,l2);
        return l1;
       }
       else{
        l2->next=merge(l1,l2->next);
        return l2;
       }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size()) return NULL;
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            int size=lists.size();
            lists[size-2]=merge(lists[size-2],lists[size-1]);
            lists.pop_back();
        }
       return lists[0];
    }
};