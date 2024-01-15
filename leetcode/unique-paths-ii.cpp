class Solution {
public:
    //O(N*N) Dynamic Programming Approach
    int uniquePathsWithObstacles(vector<vector<int>> tab) {
        int n = tab[0].size(),  m = tab.size();
        int dp[107][107] = {0};
        //m x n
        
        if(tab[0][0] || tab[m-1][n-1])
            return 0;

        dp[1][1] = !tab[0][0];
        for(int i=1; i<n; i++){
            tab[0][i] = (tab[0][i] || tab[0][i-1]);
            dp[1][i+1] = !tab[0][i]; 
        }

        for(int i=1; i<m; i++){
            tab[i][0] = (tab[i][0] || tab[i-1][0]);
            dp[i+1][1] = !tab[i][0];
            for(int j=1; j<n; j++){
                tab[i][j] = ((tab[i][j-1] && tab[i-1][j]) || tab[i][j]);
                dp[i+1][j+1] = !(tab[i][j]);
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i+1][j+1] = 0;
                if(tab[i-1][j] == 0)
                    dp[i+1][j+1] += dp[i][j+1];
                if(tab[i][j-1] == 0)
                    dp[i+1][j+1] += dp[i+1][j];
            }
        }
        return dp[m][n];

    }
};
