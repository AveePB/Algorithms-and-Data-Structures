#include<bits/stdc++.h>
using namespace std;

long long ans{}; 
int n{}; 

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> n;
    if(n%2 == 1)
        ans = 0; 
    else 
        ans = (long long) pow(2, n/2);
    
    cout << ans; 

    return 0; 
}
