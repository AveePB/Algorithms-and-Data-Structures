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
    ListNode go_deeper(int father, ListNode curr_list){
        if(curr_list == null )
            return curr_list;

        if(curr_list.val == father)
            return go_deeper(curr_list.val, curr_list.next);

        if(curr_list.next != null)
            if(curr_list.val == curr_list.next.val)
                return go_deeper(curr_list.val, curr_list.next);
        
        curr_list.next = go_deeper(curr_list.val, curr_list.next);
        return curr_list;
    }

    public ListNode deleteDuplicates(ListNode head) {
        return go_deeper(-1000, head);
    }
}
