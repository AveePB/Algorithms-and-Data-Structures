#include<iostream>
using namespace std;

const int MAX_W = 1e4+7;
const int INF = 1e9;

int n, value, weight, total_weight, dp[MAX_W];

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    fill_n(dp, MAX_W, INF);
    dp[0] = 0;
    cin >> total_weight >> n;

    for(int i=0; i<n; i++) {
        cin >> value >> weight; 
        for(int curr=weight; curr<=total_weight; curr++)
            dp[curr] = min(dp[curr], dp[curr-weight] + value);
    }
    if(dp[total_weight] == INF) 
        cout << "NIEMOZLIWE";
    else
        cout << dp[total_weight];
    return 0;
}
