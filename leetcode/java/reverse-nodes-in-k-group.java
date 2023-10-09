class Solution {
    void reverseArr(ListNode[] arr, int l, int r) {
        while(l < r) {
            ListNode l_val = arr[l];
            arr[l] = arr[r];
            arr[r] = l_val;

            arr[l-1].next = arr[l];
            arr[r].next = arr[r+1];
            l++; r--;
        }
        arr[r].next = arr[r+1];
        arr[r-1].next = arr[r];
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode[] arr = new ListNode[5001];
        ListNode root = head;
        int ptr = 1;
        while (root != null) {
            arr[ptr++] = root;
            root = root.next;
        }

        arr[0] = new ListNode(0);
        arr[ptr] = new ListNode(0);

        for(int i=1; i<ptr-k+1; i+=k) {
            //arr[i-1].next = arr[i+k-1];
            reverseArr(arr, i, i + k - 1);
        }

        arr[ptr-1].next = null;
        return arr[1];
    }
}
