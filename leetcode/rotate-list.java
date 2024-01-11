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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) return head;

        ListNode prev = head;
        ListNode curr = head.next;
        int n = 1;

        while(curr != null) {
            prev = curr;
            curr = curr.next;
            n++;
        }

        k %= n;
        if(k == 0) return head;

        prev.next = head;
        for(int i=0; i<n-k; i++)
            prev = prev.next;

        head = prev.next;
        prev.next = null;
        
        return head;
    }
}
