#include <bits/stdc++.h>

using namespace std; 

vector<int> dp; 
int n{}, c{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n; 
    dp.resize(n+1); 

    for(int i=1; i<=n; i++)
        cin >> dp[i]; 

    for(int i=1; i<=n; i++){
        if(dp[i] == 0){
            c++; 
        }
        else if(dp[i] == 3){
            dp[i] -= dp[i-1]; 
        }
        else{
            if (dp[i] == dp[i-1]){ 
                dp[i] = 0;
                c++; 
            }
        }

    }
    cout << c << endl;
    
    return 0; 
}
