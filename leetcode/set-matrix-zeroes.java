class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int[] row = new int[n], col = new int[m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] != 0)
                    continue;
                row[i]++;
                col[j]++;
            }
        }
        for(int i=0; i<n; i++) {
            if(row[i] == 0)
                continue;
            for(int j=0; j<m; j++)
                matrix[i][j] = 0;
        }
        for(int i=0; i<m; i++) {
            if(col[i] == 0)
                continue;
            for(int j=0; j<n; j++)
                matrix[j][i] = 0;
        }
    }
}
