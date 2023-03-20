#include <iostream>
#include <algorithm>
  
using namespace std;

typedef long long LL;

const int MAXN = 4000;
int dp[MAXN + 3] = {0};
  
int main() {
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    int n, abc[4]; 
    cin >> n >> abc[0] >> abc[1] >> abc[2];
    
    for(int i = 1; i <= n; i++) 
        dp[i] = -100000000; // DP [0] is initialized to 0, 
            //the other initialization is infinite
    
    for(int i = 0; i < 3; i++){
        for(int j=abc[i]; j<=n; j++){
            int current_max = dp[j - abc[i]] + 1;
            dp[j] = max(dp[j], current_max); 
        }   
    }
        
    cout << dp[n] << endl << endl;
    
    for(int i=0; i<=n; i++){
        cout << dp[i] << endl; 
    }
    
    return 0;
}
