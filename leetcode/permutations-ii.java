public class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    boolean [] vis;
    int [] nums;

    void backtracking(List<Integer> l, int idx){
        l.add(this.nums[idx]);
        vis[idx] = true;

        if(l.size() < this.nums.length) {
            for (int i = 0; i < this.nums.length; i++) {
                if(i > 0 && !this.vis[i-1])
                    if(this.nums[i - 1] == this.nums[i])
                        continue;
                if (vis[i])
                    continue;
                backtracking(new ArrayList<>(l), i);
            }
        }
        else{
            ans.add(l);
        }

        vis[idx] = false;
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        this.vis = new boolean[nums.length];
        this.nums = nums;

        for(int i=0; i<this.nums.length; i++) {
            if (i > 0 && this.nums[i - 1] == this.nums[i])
                continue;
            backtracking(new ArrayList<>(), i);
        }
        return this.ans;
    }
}
