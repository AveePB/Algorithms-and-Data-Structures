class Solution {
    char[] s, p;
    int[][] dp;
    int solve(int i, int j) {
        if(dp[i][j] != 0) return dp[i][j];
        if(i == s.length && j == p.length) return 1;
        if(j == p.length) return -1;

        boolean is_match = ((i < s.length) && (s[i] == p[j] || p[j] == '.'));
        if((j+1 < p.length) && p[j+1] == '*') {
            dp[i][j] = solve(i, j+2);
            if(is_match) dp[i][j] = Math.max(dp[i][j], solve(i+1, j));
            return dp[i][j];
        }
        if(is_match)
            dp[i][j] = solve(i+1, j+1);
        else
            dp[i][j] = -1;
        return dp[i][j];
    }

    public boolean isMatch(String s, String p) {
        int n = s.length(), m = p.length();
        this.dp = new int[n+1][m+1];
        this.s = s.toCharArray();
        this.p = p.toCharArray();
        int ans = solve(0, 0);
        return (ans == 1);
    }
}