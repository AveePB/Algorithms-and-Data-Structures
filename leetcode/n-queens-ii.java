class Solution {
    boolean[] posCol, posNeg, posDiag;

    int backtracking(int row, int n) {
        if(row == n) return 1;

        int res = 0;
        for(int cln=0; cln<n; cln++) {
            if(this.posNeg[row-cln+n]) continue;
            if(this.posDiag[row+cln]) continue;
            if(this.posCol[cln]) continue;

            this.posNeg[row-cln+n] = true;
            this.posDiag[row+cln] = true;
            this.posCol[cln] = true;

            res += backtracking(row+1, n);

            this.posNeg[row-cln+n] = false;
            this.posDiag[row+cln] = false;
            this.posCol[cln] = false;
        }
        return res;
    }

    public int totalNQueens(int n) {
        this.posCol = new boolean[n];
        this.posNeg = new boolean[2*n];
        this.posDiag = new boolean[2*n];
        return backtracking(0, n);
    }
}
