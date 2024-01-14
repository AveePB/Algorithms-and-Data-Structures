class Solution {
public:
    //O(N*N) Dynamic Programming Approach
    int uniquePaths(int m, int n) {
        int dp[107][107];
        for(int i=1; i<=n; i++)
            dp[1][i] = 1;
        for(int i=1; i<=m; i++)
            dp[i][1] = 1;
            
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];

        return dp[m][n];
    }
};
