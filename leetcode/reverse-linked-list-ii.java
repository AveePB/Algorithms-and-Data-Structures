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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode[] nodes = new ListNode[501];
        ListNode curr = head;
        int ptr = 0;

        while(curr != null) {
            nodes[ptr++] = curr;
            curr = curr.next;
        }
        left--;
        right--;

        if(left > 0) nodes[left-1].next = nodes[right];
        nodes[left].next = nodes[right+1];

        for(int i=left; i<right; i++)
            nodes[i+1].next = nodes[i];

        if(left == 0) return nodes[right];

        return nodes[0];
    }
}
