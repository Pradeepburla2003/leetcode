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
    public ListNode reverseList(ListNode head) {
        ListNode temp;
        ListNode rev = null;
        while(head != null){
            temp = head.next;
            head.next = rev;
            rev = head;
            head = temp;
        }
        return rev;
    }
}