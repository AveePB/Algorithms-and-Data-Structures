class Solution {
    public void nextPermutation(int[] nums) {
        int n = 1;
        for(int i=nums.length-2; i>=0; i--) {
            if(!(nums[i] >= nums[i+1])) break;
            n++;
        }

        if(n == nums.length) {
            Arrays.sort(nums);
            return;
        }


        int idx = nums.length - (1+n), next_idx = idx, next_val = -1;
        Arrays.sort(nums, idx+1, nums.length);

        for(int i=idx+1; i<nums.length; i++) {
            if(!(nums[idx] < nums[i])) continue;
            next_idx = i;
            break;
        }
        next_val = nums[next_idx];
        nums[next_idx] = nums[idx];
        nums[idx] = next_val;
    }
}
