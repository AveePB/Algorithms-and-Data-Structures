class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int l = -1;
        for(int i=0; i<intervals.length; i++) {
            if(!(intervals[i][1] < newInterval[0])) break;
            l++;
        }

        int r = intervals.length-1;
        for(int i=intervals.length-1; i>=0; i--) {
            if(!(intervals[i][0] > newInterval[1])) break;
            r--;
        }
        // l == r than we insert new interval into l+1
        // l < r than we merge new interval to the range <l+1, r>
        if(l == r) {
            l++; r++;
            int[][] res = new int[intervals.length+1][2];
            int l_len = Math.min(l, intervals.length-1);

            for(int i=0; i<=l_len; i++) res[i] = intervals[i];
            res[l] = newInterval;
            for(int i=r; i<intervals.length; i++) res[i+1] = intervals[i];

            return res;
        }
        int[][] res = new int[intervals.length-(r-l)+1][2];
        l++;
        for(int i=0; i<l; i++) res[i] = intervals[i];
        res[l] = new int[]{Math.min(intervals[l][0], newInterval[0]), Math.max(intervals[r][1], newInterval[1])};

        for(int i=r+1; i<intervals.length; i++) res[i-r+l] = intervals[i];
        return res;
    }
}
