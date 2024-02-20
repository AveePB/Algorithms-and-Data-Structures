class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length < 3) return nums.length;
        int[] arr = nums.clone();
        int ptr = 2;

        for(int i=2; i<nums.length; i++) {
            if(arr[i] == arr[i-2]) continue;
            nums[ptr++] = arr[i];
        }
        return ptr;
    }
}
