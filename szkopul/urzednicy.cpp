#include<iostream>
using namespace std;

const int N = 1e6+7;
int n{}, ans{}, tab[N] = {0}, dp[N] = {0};

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n;
    for(int i=2; i<=n; i++)
        cin >> tab[i];

    for(int i=n; i>0; i--){
        if(dp[i] == 0){
            dp[tab[i]]++;
        }
        else{ 
            dp[tab[i]] += dp[i] - 1;
            dp[i] = 1;
        }
    }

    for(int i=1; i<=n; i++)
        if(dp[i] > 0)
            ans++;

    cout << ans;
    
    return 0;
}
