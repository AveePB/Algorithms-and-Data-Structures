#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7; 
vector<int> dp(MAXN), a(MAXN), t(MAXN); 
int n{}, k{}, ans{}; 

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> k; 

    for(int i=0; i<n; i++)
        cin >> a[i]; 
    
    for(int i=0; i<n; i++)
        cin >> t[i]; 

    for(int i=0; i<n; i++){
        if(!t[i]) 
            dp[i+1] = a[i]; 
        else 
            ans += a[i];
        dp[i+1] += dp[i]; 
    }

    int idx = 1;
    for(int i=1; i<=(n-k+1); i++){
        int j = i+k-1; 
        if((dp[idx+k-1] - dp[idx-1]) < (dp[j] - dp[i-1]))
            idx = i;
    }

    ans += dp[idx+k-1] - dp[idx-1];
    cout << ans << '\n';

    return 0; 
}
