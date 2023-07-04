#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
long long ans{}, s{};
int n, m, v[N];

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        int p, k;
        cin >> p >> k;
        v[p]++, v[k]++;
    }

    for(int i=1; i<=n; i++)
        s += v[i] * (n - 1 - v[i]);

    s /= 2;
    ans = (n*(n-1)*(n-2))/6;
    cout << (ans - s);

    return 0;
}
