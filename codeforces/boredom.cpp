#include <bits/stdc++.h>
 
using namespace std;
 
const long long maxn = 100005;

int n;
 
int main() {
    cin >> n;
    long long a[maxn] = {0};
    long long temp;

    for (long long i = 1; i <= n; i++) {
        cin >> temp;
        a[temp] ++;
    }

    long long dp[maxn];

    dp[1] = a[1] * 1;
    dp[2] = a[2] * 2;
    dp[3] = a[3] * 3 + dp[1];

    for (long long i = 4; i < maxn; i++) {
        dp[i] = max(dp[i-1], max(dp[i-2] + a[i] * i, dp[i-3] + a[i] * i));
    }
    cout << dp[maxn-1] << endl;
}
