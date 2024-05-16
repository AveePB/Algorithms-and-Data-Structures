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
    void solve(ListNode l1, ListNode l2, int add) {
        if((l1 == null && l2 == null)){
            if(add > 0)
                l1 = new ListNode(add);
            return;
        }
        if(l1 != null && l2 != null) {
            l1.val += l2.val;
            l1.val += add;
            solve(l1.next, l2.next, l1.val/10);
            l1.val %= 10;
        }        
        else if(l1 != null && l2 == null) {
            l1.val += add;
            solve(l1.next, null, l1.val/10);
            l1.val %= 10;
        }
        else{
            l1 = new ListNode();
            l1.val += l2.val;
            l1.val += add;
            solve(null, l2.next, l1.val/10);
            l1.val %= 10;
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        solve(l1, l2, 0);
        return l1;
    }
}
