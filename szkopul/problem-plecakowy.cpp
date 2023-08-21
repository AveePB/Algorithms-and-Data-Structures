#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 1e3+7; 

vector<long long> values (MAXN), weights(MAXN);
long long n{}, max_weight{};

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n >> max_weight; 
    
    for(int i=0; i<n; i++)
        cin >> weights[i]; 

    for(int i=0; i<n; i++)
        cin >> values[i];

    vector<long long> dp(max_weight+1);

    for(int i=1; i<=n; i++)
        for(int j=max_weight; j>=0; j--)
            if(weights[i-1] <= j)
                dp[j] = max(dp[j], dp[j-weights[i-1]] + values[i-1]); 
    
    cout << dp[max_weight] << endl; 

    return 0; 
}
