class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    int target;
    int[] nums;

    void backtracking(List<Integer> l, int idx, int sum){
        sum += this.nums[idx];
        l.add(this.nums[idx]);

        if(sum == this.target){
            this.ans.add(l);
            return;
        }

        for(int i=idx; i<this.nums.length; i++)
            if(this.nums[i]+sum <= this.target)
                backtracking(new ArrayList<>(l), i, sum);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        this.nums = candidates;
        this.target = target;

        for(int i=0; i<this.nums.length; i++)
            backtracking(new ArrayList<>(), i, 0);

        return this.ans;
    }
}
