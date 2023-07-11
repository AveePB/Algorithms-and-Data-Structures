#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int min_tab[N], max_tab[N];
int n{}, a{}, ans{};

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> n;
    min_tab[0] = INT_MAX;
    max_tab[n+1] = 0;
    
    for(int i=1; i<=n; i++){
        cin >> a;
        min_tab[i] = a;
        max_tab[i] = a;
    }

    for(int i=1; i<=n; i++)
        min_tab[i] = min(min_tab[i], min_tab[i-1]);
    
    for(int i=n; i>0; i--)
        max_tab[i] = max(max_tab[i], max_tab[i+1]);

    for(int i=1; i<=n; i++)
        ans = max(ans, (max_tab[i]-min_tab[i]));

    cout << ans;

    return 0;
}
