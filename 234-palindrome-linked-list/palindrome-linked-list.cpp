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
        // if(!head) return 0;
        if(!head->next) return 1;
        ListNode* slow=head;
        ListNode* fast=head;
        vector<int>s;
        while(fast && fast->next){
            s.push_back(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        // cout<<s<<" "<<slow->val;;
        if(fast && !fast->next){
            // cout<<slow->val<<endl;
            // cout<<1;
            slow=slow->next;
        }
        
        int size=s.size()-1;
        while(slow){
            if(s[size]!=slow->val) return 0;
            slow=slow->next;
            size-=1;
        }
        return 1;
    }
};