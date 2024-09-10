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
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // if(!head->next) return head;
        ListNode* ans = head;
        ListNode* link;
        while(head->next){
            int gc = gcd(head->val,head->next->val);
            ListNode* mid = new ListNode(gc);
            link = head->next;
            mid->next = link;
            head->next = mid;
            head = link;
        }
        return ans;
    }
};