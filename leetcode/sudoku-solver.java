class Solution {
    private boolean[][] is_cln = new boolean[9][9], is_row = new boolean[9][9];
    private boolean[][][] is_square = new boolean[3][3][9];
    private boolean backtracking(char[][] mat, int row, int cln) {
        if(row == 9) return true;

        int next_row = row + (cln+1) / 9, next_cln = (cln+1) % 9;
        if(mat[row][cln] != '.') return backtracking(mat, next_row, next_cln);

        for(int i=0; i<9; i++) {
            if(this.is_cln[cln][i] || this.is_row[row][i]) continue;
            if(this.is_square[row/3][cln/3][i]) continue;

            mat[row][cln] = (char) ('1' + i);
            this.is_cln[cln][i] = true;
            this.is_row[row][i] = true;
            this.is_square[row/3][cln/3][i] = true;

            if(backtracking(mat, next_row, next_cln)) return true;

            mat[row][cln] = '.';
            this.is_cln[cln][i] = false;
            this.is_row[row][i] = false;
            this.is_square[row/3][cln/3][i] = false;
        }
        return false;
    }

    public void solveSudoku(char[][] board) {
        for(int row=0; row<9; row++) {
            for(int cln=0; cln<9; cln++) {
                if(board[row][cln] == '.') continue;
                int val = board[row][cln] - '1';

                this.is_cln[cln][val] = true;
                this.is_row[row][val] = true;
                this.is_square[row/3][cln/3][val] = true;
            }
        }
        backtracking(board, 0, 0);
    }
}
