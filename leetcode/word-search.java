public class Solution {
    char[][] mat;
    String str;
  
    boolean dfs(int row, int cln, int idx){
        if(idx+1 == str.length())
            return true;

        char curr_char = mat[row][cln];
        mat[row][cln] = ' ';

        if(row-1 >= 0 && mat[row-1][cln] == this.str.charAt(idx+1))
            if(dfs(row-1, cln, idx+1))
                return true;

        if(row+1 < mat.length && mat[row+1][cln] == this.str.charAt(idx+1))
            if(dfs(row+1, cln, idx+1))
                return true;

        if(cln-1 >= 0 && mat[row][cln-1] == this.str.charAt(idx+1))
            if(dfs(row, cln-1, idx+1))
                return true;

        if(cln+1 < mat[0].length && mat[row][cln+1] == this.str.charAt(idx+1))
            if(dfs(row, cln+1, idx+1))
                return true;
        
        mat[row][cln] = curr_char;
        return false;
    }

    public boolean exist(char[][] board, String word) {
        this.mat = board;
        this.str = word;
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[i].length; j++){
                if(board[i][j] != word.charAt(0))
                    continue;
                if(dfs(i, j, 0))
                    return true;
            }
        }
        return false;
    }
}
