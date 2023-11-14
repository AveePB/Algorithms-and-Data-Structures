class Solution {
    public int maxArea(int[] height) {
        int i=0, j=height.length-1, ans=0;
        while (i < j){
            int curr = (j-i) * Math.min(height[i], height[j]);
            ans = Math.max(ans, curr);

            if(height[i] <= height[j])
                i++;
            else
                j--;
        }

        return ans;
    }
}