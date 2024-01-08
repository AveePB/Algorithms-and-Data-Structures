class Solution {
    private void go_right(int[][]mat, int val, int row, int col) {
        mat[row][col] = val;
        if(col+1 < mat.length && mat[row][col+1] == 0)
            go_right(mat, val+1, row, col+1);
        else if(row+1 < mat.length && mat[row+1][col] == 0)
            go_down(mat, val+1, row+1, col);
    }

    private void go_down(int[][] mat, int val, int row, int col) {
        mat[row][col] = val;
        if(row+1 < mat.length && mat[row+1][col] == 0)
            go_down(mat, val+1, row+1, col);
        else if(col-1 >= 0 && mat[row][col-1] == 0)
            go_left(mat, val+1, row, col-1);
    }

    private void go_left(int[][] mat, int val, int row, int col) {
        mat[row][col] = val;
        if(col-1 >= 0 && mat[row][col-1] == 0)
            go_left(mat, val+1, row, col-1);
        else if(row-1 >= 0 && mat[row-1][col] == 0)
            go_up(mat, val+1, row-1, col);
    }

    private void go_up(int[][] mat, int val, int row, int col) {
        mat[row][col] = val;
        if(row-1 >= 0 && mat[row-1][col] == 0)
            go_up(mat, val+1, row-1, col);
        else if(col+1 < mat.length && mat[row][col+1] == 0)
            go_right(mat, val+1, row, col+1);
    }

    public int[][] generateMatrix(int n) {
        int[][] mat = new int[n][n];
        go_right(mat, 1, 0, 0);
        return mat;
    }
}
