class Solution {
     public String deleteDupAsterisk(String str) {
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<str.length(); i++){
            if(i > 0 && (str.charAt(i-1) == str.charAt(i) && str.charAt(i) == '*'))
                continue;
            sb.append(str.charAt(i));
        }
        return sb.toString();
    }

    public boolean isMatch(String s, String p) {
        char[] pattern = deleteDupAsterisk(p).toCharArray();
        char[] str = s.toCharArray();

        int n = str.length, m = pattern.length;
        boolean[][] dp = new boolean[m+1][n+1];
        dp[0][0] = true;

        if(m > 0 && (pattern[0] == '*'))
            dp[1][0] = true;

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if((pattern[i-1] == str[j-1]) || (pattern[i-1] == '?'))
                    dp[i][j] = dp[i-1][j-1];
                else if(pattern[i-1] == '*')
                    dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
}
