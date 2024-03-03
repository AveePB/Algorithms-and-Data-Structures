class Solution {
    //Structures:
    Boolean[][][] dp;
    char[] s1, s2;


    //INCLUSIVE BOUNDARIES!!!
    public boolean scramble(int leftIdx1, int rightIdx1, int leftIdx2) {
        if (this.dp[leftIdx1][rightIdx1][leftIdx2] != null)
            return this.dp[leftIdx1][rightIdx1][leftIdx2];

        if (leftIdx1 == rightIdx1)
            return this.dp[leftIdx1][rightIdx1][leftIdx2] = (this.s1[leftIdx1] == this.s2[leftIdx2]);

        for (int i = 0; i < (rightIdx1 - leftIdx1); i++) {
            if (scramble(leftIdx1, leftIdx1+i, leftIdx2) &&
                    scramble(leftIdx1+i+1, rightIdx1, leftIdx2+i+1))

                return this.dp[leftIdx1][rightIdx1][leftIdx2] = true;


            if (scramble(rightIdx1-i, rightIdx1, leftIdx2) &&
                    scramble(leftIdx1, rightIdx1-i-1, leftIdx2+i+1))

                return this.dp[leftIdx1][rightIdx1][leftIdx2] = true;
        }

        return this.dp[leftIdx1][rightIdx1][leftIdx2] = false;
    }


    public boolean isScramble(String s1, String s2) {
        int n = s1.length();
        this.dp = new Boolean[n][n][n];

        this.s1 = s1.toCharArray();
        this.s2 = s2.toCharArray();

        return scramble(0, s1.length()-1, 0);
    }
}
