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
    ListNode* doubleIt(ListNode* head) {
        vector<int>nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
        int k=0;
        for(int i=nums.size()-1;i>=0;i--){
            nums[i]=nums[i]*2+k;
            if(nums[i]>9){
                k=nums[i]/10;
                nums[i]=nums[i]%10;
            }
            else k=0;
        }
        ListNode* temp=new ListNode(NULL);
        ListNode* ans=temp;
        if(k>0){
            ListNode* temp1=new ListNode(k);
            temp->next=temp1;
            temp=temp->next;
        }
        for(int i=0;i<nums.size();i++){
            ListNode* temp1=new ListNode(nums[i]);
            temp->next=temp1;
            temp=temp->next;
        }
        return ans->next;
        
    }
};