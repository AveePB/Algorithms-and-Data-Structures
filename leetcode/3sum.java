class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> ans = new HashSet<>();
        int n = nums.length;
        Arrays.sort(nums);

        for(int l=0; l<n-2; l++){
            int mid = l+1;
            int r = n-1;

            while (mid < r){
                int sum = nums[l] + nums[mid] + nums[r];
                if(sum == 0){
                    ans.add(Arrays.asList(nums[l], nums[mid], nums[r]));
                    mid++;
                    r--;
                }
                else if(sum > 0){
                    r--;
                }
                else{
                    mid++;
                }
            }
        }
        return new ArrayList<>(ans);
    }
}
