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
    int target;
    public ListNode deleteNode(ListNode root, int nth) {
        if(nth == this.target)
            return root.next;
        
        root.next = deleteNode(root.next, nth-1);
        return root;
    }


    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode node = head;
        int len = 0;
        
        while(node != null) {
            node = node.next;
            len++;
        }

        this.target = n;


        return deleteNode(head, len);
    }
}
