class Solution {

    public double solve(double b, int p) {
        if(p == 0)
            return 1;

        double val = solve(b, p/2);

        if(p%2 == 0)
            return val * val;
        return val * val * b;
    }

    public double myPow(double x, int n) {
        if((x <= -2 || 2 <= x) && !(-31 < n && n < 31))
            return 0;
        if(x == -1) {
            if(n%2 == 0)
                return 1;
            else
                return -1;
        }
        if(n < 0){
            x = 1 / x;
            n *= -1;
        }

        if(x == 1)
            return 1;

        return solve(x, n);
    }
}
