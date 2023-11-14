class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = 100000;
        for(int i=0; i<nums.length-1; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int l = i+1, r = nums.length-1;
            while (l < r) {
                while (l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if(Math.abs(target-ans) > Math.abs(target-sum)) ans = sum;
                    if(sum < target)
                        l++;
                    else if(sum > target)
                        r--;
                    else
                        return target;
                }
            }
        }
        return ans;
    }
}
