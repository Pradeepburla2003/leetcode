/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sum = new ListNode(0);
        ListNode res = sum;
        int carry = 0;
        while(l1 != null && l2 != null){
            int add = l1.val + l2.val + carry;
            if(add > 9) carry = 1;
            else carry = 0;
            ListNode newNode = new ListNode(add%10);
            sum.next = newNode;
            sum = sum.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1 != null){
            int add = l1.val + carry;
            if(add < 10) carry = 0;
            else carry = 1;
             ListNode newNode = new ListNode(add%10);
            sum.next = newNode;
            sum = sum.next;
            l1 = l1.next;
        }
        while(l2 != null){
            int add = l2.val + carry;
            if(add < 10) carry = 0;
            else carry = 1;
             ListNode newNode = new ListNode(add%10);
            sum.next = newNode;
            sum = sum.next;
            l2 = l2.next;
        }
        if(carry == 1) sum.next = new ListNode(1);
        return res.next;
    }
}