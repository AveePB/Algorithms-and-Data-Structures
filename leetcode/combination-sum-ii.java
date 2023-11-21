public class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    boolean[] vis;
    int[] nums;
    int target;

    void backtracking(List<Integer> l, int idx, int sum){
        vis[idx] = true;
        l.add(nums[idx]);
        sum += nums[idx];
        if(sum == this.target)
            ans.add(l);
        else
            for(int i=idx+1; i<this.nums.length; i++){
                if(sum + nums[i] > this.target)
                    continue;
                if(i > idx+1 && !vis[i-1])
                    if(this.nums[i-1] == this.nums[i])
                        continue;
                if(vis[i])
                    continue;
                backtracking(new ArrayList<>(l), i, sum);
            }

        vis[idx] = false;
    }


    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.nums = candidates;
        this.target = target;

        this.vis = new boolean[this.nums.length];

        for(int i=0; i<this.nums.length; i++){
            if(i > 0 && this.nums[i-1] == this.nums[i])
                continue;
            backtracking(new ArrayList<>(), i, 0);
        }

        return this.ans;
    }
}
