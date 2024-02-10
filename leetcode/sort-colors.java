class Solution {
    public void sortColors(int[] nums) {
        int[] colors = new int[3];
        for(int i=0; i<nums.length; i++)
            colors[nums[i]]++;

        int c=0, idx=0;
        while (idx < nums.length) {
            while(colors[c] == 0)
                c++;
            colors[c]--;

            nums[idx] = c;
            idx++;
        }
    }
}
