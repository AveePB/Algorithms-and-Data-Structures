class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] cpy = Arrays.copyOf(nums1, m);
        int i=0, j=0;
        for(int idx=0; idx<n+m; idx++) {
            if(i == m){
                nums1[idx] = nums2[j];
                j++;
                continue;
            }

            if(j == n){
                nums1[idx] = cpy[i];
                i++;
                continue;
            }

            if(cpy[i] <= nums2[j]){
                nums1[idx] = cpy[i];
                i++;
            }
            else{
                nums1[idx] = nums2[j];
                j++;
            }
        }
    }
}
