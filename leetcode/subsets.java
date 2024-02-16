class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    int [] nums;

    void backtracking(int idx, List<Integer> l){
        l.add(nums[idx]);
        for(int i=idx+1; i< nums.length; i++)
            backtracking(i, new ArrayList<>(l));
        ans.add(l);
    }



    public List<List<Integer>> subsets(int[] nums) {
        ans.add(new ArrayList<>());
        this.nums = nums;
        for(int i=0; i<nums.length; i++)
            backtracking(i, new ArrayList<>());

        return ans;

    }
}
