class Solution {
    final int MAX_VAL = 100000;
    public int firstMissingPositive(int[] nums) {
        boolean[] seen = new boolean[MAX_VAL+1];
        int res = MAX_VAL+1;

        for(int num: nums) {
            if(!(0 < num && num < MAX_VAL+1)) continue;
            seen[num] = true;
        }

        for(int i=1; i<MAX_VAL+1; i++) {
            if(seen[i]) continue;
            res = i;
            break;
        }
        return res;
    }
}
