class Solution {
    List<Integer> res = new ArrayList<>();
    boolean[][] vis;
    int[][] mat;

    void dfs(int row, int col, int dir) {
        vis[row][col] = true;
        res.add(mat[row][col]);

        if(dir == 0) {
            if(row-1 >= 0 && !vis[row-1][col])
                dfs(row-1, col, 0);
            else if(col+1 < mat[0].length && !vis[row][col+1])
                dfs(row, col+1, 3);
        }
        else if (dir == 1) {
            if(row+1 < mat.length && !vis[row+1][col])
                dfs(row+1, col, 1);
            else if(col-1 >= 0 && !vis[row][col-1])
                dfs(row, col-1, 2);
        }
        else if(dir == 2) {
            if(col-1 >= 0 && !vis[row][col-1])
                dfs(row, col-1, 2);
            else if(row-1 >= 0 && !vis[row-1][col])
                dfs(row-1, col, 0);
        }
        else {
            if(col+1 < mat[0].length && !vis[row][col+1])
                dfs(row, col+1, 3);
            else if(row+1 < mat.length && !vis[row+1][col])
                dfs(row+1, col, 1);
        }
    }
    public List<Integer> spiralOrder(int[][] matrix) {
        this.vis = new boolean[matrix.length][matrix[0].length];
        this.mat = matrix;
        dfs(0,0, 3);
        return this.res;
    }
}
