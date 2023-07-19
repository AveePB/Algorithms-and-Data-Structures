#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+7; 

int n, sum=0, arr[MAXN]; 

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i]; 
    }

    int max_s = (sum+1)/2, dp[max_s+1];
    fill_n(dp, max_s+1, 0);

    for(int i=0; i<n; i++) {
        if(arr[i] <= max_s)
            for(int j=max_s; j>0; j--) {
                if(arr[i] <= j) dp[j] = max(dp[j], dp[j-arr[i]] + arr[i]);
        }
    }

    int son1 = max(sum-dp[max_s], dp[max_s]); 
    int son2 = min(sum-dp[max_s], dp[max_s]);

    cout << son1 << ' ' << son2 << endl; 

    return 0;
}
