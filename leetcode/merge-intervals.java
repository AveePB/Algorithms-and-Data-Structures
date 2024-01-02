class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (i1, i2) -> Integer.compare(i1[0], i2[0]));
        int idx = 0;

        for(int i=1; i< intervals.length; i++) {
            if(intervals[i-1][1] >=  intervals[i][0]) {
                intervals[i][0] = Math.min(intervals[i-1][0], intervals[i][0]);
                intervals[i][1] = Math.max(intervals[i-1][1], intervals[i][1]);
            }
            else {
                intervals[idx][0] = intervals[i-1][0];
                intervals[idx][1] = intervals[i-1][1];
                idx++;
            }
        }
        intervals[idx][0] = intervals[intervals.length-1][0];
        intervals[idx][1] = intervals[intervals.length-1][1];
        idx++;

        return Arrays.copyOfRange(intervals, 0, idx);
    }
}
