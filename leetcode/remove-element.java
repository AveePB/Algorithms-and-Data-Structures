class Solution {
    public int removeElement(int[] nums, int val) {
        int ptr = 0;
        for(int i=0; i<nums.length; i++) {
            if(nums[i] == val) continue;
            nums[ptr++] = nums[i];
        }
        return ptr;
    }
}
