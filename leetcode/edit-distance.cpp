class Solution {
public:
    int minDistance(string w1, string w2) {
        int len{}, dp[w1.size()+1][w2.size()+1];
        for(int i=0; i<=w1.size(); i++) dp[i][0] = i;
        for(int i=0; i<=w2.size(); i++) dp[0][i] = i;

        for(int i=1; i<=w1.size(); i++){
            for(int j=1; j<=w2.size(); j++){
                if(w1[i-1] == w2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{    
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                    dp[i][j] += 1;
                }
            }
        } 

        return dp[w1.size()][w2.size()];
    }
};
