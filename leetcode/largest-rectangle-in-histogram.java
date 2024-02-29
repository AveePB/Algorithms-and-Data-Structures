class Solution {
    class Rect {
        public int start;
        public int height;
        public Rect(int start, int height) {
            this.start = start;
            this.height = height;
        }
    }


    public int largestRectangleArea(int[] heights) {
        int ans=0, n = heights.length;
        Stack<Rect> stck = new Stack<>();

        for(int i=0; i<n; i++){
            int start = i;
            while ((!stck.isEmpty()) && (stck.peek().height > heights[i])){
                Rect rect = stck.pop();
                start = Math.min(start, rect.start);

                int rect_area = (i-rect.start) * rect.height;
                ans = Math.max(ans, rect_area);
            }
            stck.push(new Rect(start, heights[i]));
        }
        while (!stck.isEmpty()){
            Rect rect = stck.pop();
            int rect_area = (n-rect.start) * rect.height;
            ans = Math.max(ans, rect_area);
        }

        return ans;
    }
}
