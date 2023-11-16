class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[][][] squares = new int[3][3][9];
        int[][] rows = new int[9][9];
        int[][] cols = new int[9][9];

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if(squares[i/3][j/3][num] == 1)
                    return false;
                if(rows[i][num] == 1)
                    return false;
                if(cols[j][num] == 1)
                    return false;

                squares[i/3][j/3][num]++;
                rows[i][num]++;
                cols[j][num]++;
            }
        }
        return true;
    }
}
