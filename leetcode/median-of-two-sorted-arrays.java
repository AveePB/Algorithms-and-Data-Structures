class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int i=0, j=0;
        int mid = (n+m+1) / 2;
        int v1 = 0, v2 = 0;

        if(n == 0 && m == 1) return nums2[0];
        if(n == 1 && m == 0) return nums1[0];

        for(int idx=0; idx<=mid; idx++) {
            v2 = v1;
            if(i == n) v1 = nums2[j++];
            else if(j == m) v1 = nums1[i++];
            else if(nums1[i] <= nums2[j])
                v1 = nums1[i++];
            else
                v1 = nums2[j++];
        }
        if((n+m)%2 == 1) return v2;
        return ((double) v2 + (double) v1)/2;
    }
}
