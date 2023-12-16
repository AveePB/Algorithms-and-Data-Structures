class Solution {
    List<List<String>> ans = new ArrayList<>();
    boolean[] posCol, posNeg, posDiag;

    void backtracking(List<String> mat, int row, int n) {
        if(row == n) {
            this.ans.add(new ArrayList<>(mat));
            return;
        }

        char[] curr = new char[n];
        Arrays.fill(curr, '.');

        for(int cln=0; cln<n; cln++) {
            if(this.posNeg[row-cln+n]) continue;
            if(this.posDiag[row+cln]) continue;
            if(this.posCol[cln]) continue;

            this.posNeg[row-cln+n] = true;
            this.posDiag[row+cln] = true;
            this.posCol[cln] = true;
            curr[cln] = 'Q';
            mat.add(String.valueOf(curr));

            backtracking(mat, row+1, n);

            mat.remove(mat.size()-1);
            this.posNeg[row-cln+n] = false;
            this.posDiag[row+cln] = false;
            this.posCol[cln] = false;
            curr[cln] = '.';
        }
    }


    public List<List<String>> solveNQueens(int n) {
        this.posCol = new boolean[n];
        this.posNeg = new boolean[2*n];
        this.posDiag = new boolean[2*n];
        backtracking(new ArrayList<>(), 0, n);
        return this.ans;
    }
}
