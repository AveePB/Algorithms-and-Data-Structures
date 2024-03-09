class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    int [] nums;
    void backtracking(List<Integer> l, int idx){
        l.add(this.nums[idx]);
        for(int i=idx+1; i<this.nums.length; i++) {
            if (i > idx + 1 && this.nums[i - 1] == this.nums[i])
                continue;
            backtracking(new ArrayList<>(l), i);
        }
        this.ans.add(l);
    }
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        this.ans.add(new ArrayList<>());
        Arrays.sort(nums);
        this.nums = nums;

        for(int i=0; i<this.nums.length; i++) {
            if (i > 0 && this.nums[i - 1] == this.nums[i])
                continue;
            backtracking(new ArrayList<>(), i);
        }
        return this.ans;
    }
}
