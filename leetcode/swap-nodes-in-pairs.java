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
    public ListNode swapPairs(ListNode head) {
        ListNode[] nodes = new ListNode[102];
        ListNode curr = head;
        int ptr = 0;

        while(curr != null) {
            if(ptr % 2 == 1) {
                nodes[ptr] = nodes[ptr-1];
                nodes[ptr-1] = curr;
            }
            else {
                nodes[ptr] = curr;
            }
            curr = curr.next;
            ptr++;
        }
        for(int i=0; i<ptr; i++) nodes[i].next = nodes[i+1];
        return nodes[0];
    }
}
