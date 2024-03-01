class Solution {
    class Rect {
        public int start;
        public int height;
        public Rect(int start, int height) {
            this.start = start;
            this.height = height;
        }
    }

    public int maximalRectangleInHistogram(int[] height) {
        Stack<Rect> stck = new Stack<>();
        int n = height.length;
        int res = 0;

        for(int i=0; i<n; i++) {
            int start = i;
            while ((!stck.isEmpty()) && (stck.peek().height > height[i])) {
                Rect rect = stck.pop();
                start = Math.min(start, rect.start);

                int area = (i-rect.start) * rect.height;
                res = Math.max(res, area);
            }
            stck.push(new Rect(start, height[i]));
        }

        while (!stck.isEmpty()) {
            Rect rect = stck.pop();
            int area = (n-rect.start) * rect.height;
            res = Math.max(res, area);
        }

        return res;
    }

    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int[] arr = new int[m];
        int res = 0;

        Arrays.fill(arr, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1')
                    arr[j] += 1;
                else
                    arr[j] = 0;
            }
            res = Math.max(res, maximalRectangleInHistogram(arr));
        }

        return res;
    }
}
