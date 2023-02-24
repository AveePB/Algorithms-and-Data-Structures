#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+7;
int n{}, dp[N];

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> dp[i+1];
        dp[i+1] += dp[i];
    }

    for(int i=0; i<n; i++)
        cout << (dp[i+1]-dp[i]) << ' ';

    return 0;
}
