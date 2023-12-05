class Solution {
    final int STOP = -10000;
    int[][] mat;
    void rotateBy90Deg(int row, int col) {
        if(mat[row][col] == STOP)
            return;
        int new_row = col, new_col = mat.length - row - 1;

        int val = mat[row][col];
        mat[row][col] = STOP;

        rotateBy90Deg(new_row, new_col);
        mat[new_row][new_col] = val;
    }

    public void rotate(int[][] mat) {
        this.mat = mat;
        int st=0, en=mat.length-1;

        for(int i=0; i<mat.length/2; i++) {
            for(int j=st; j<en; j++) {
                rotateBy90Deg(i, j);
            }
            st++;
            en--;
        }
    }
}
