class Solution {
    final int M = 46340 + 1;
    public int mySqrt(int x) {
        int l=0, r=M;
        while(r-l > 1) {
            int mid = (l+r) / 2;
            if(mid*mid > x)
                r = mid;
            else
                l = mid;
        }
        return l;
    }
}
