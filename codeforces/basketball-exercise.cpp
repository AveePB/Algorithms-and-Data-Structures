#include <bits/stdc++.h>

using namespace std; 
vector<vector<long long>> dp(2, vector<long long>(10007, 0));  
int p_row{-1}, cur_row{}, n{};
long long h{}; 

int main(){
    cin >> n; 

    dp[0].resize(n); 
    for(int i=0; i<n; i++)
        cin >> dp[0][i];

    dp[1].resize(n); 
    for(int i=0; i<n; i++)
        cin >> dp[1][i]; 
    
    
    for(int i=n-2; i>=0; i--){
        dp[0][i] = max(dp[0][i]+dp[1][i+1], dp[0][i+1]);
        dp[1][i] = max(dp[1][i]+dp[0][i+1], dp[1][i+1]);
    }
    cout << max(dp[0][0],dp[1][0]) << endl;
    


    return 0; 
}
