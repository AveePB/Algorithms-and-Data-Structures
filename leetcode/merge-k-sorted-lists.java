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
    public ListNode mergeKLists(ListNode[] lists) {
        int[] tab = new int[10000];
        int ptr=0;

        for(ListNode root: lists) {
            while (root != null) {
                tab[ptr++] = root.val;
                root = root.next;
            }
        }
        Arrays.sort(tab, 0, ptr);
        if(ptr == 0) return null;

        ListNode res, node = new ListNode(tab[0]);
        res = node;
        for(int i=1; i<ptr; i++) {
            node.next = new ListNode(tab[i]);
            node = node.next;
        }
        return res;
    }
}
