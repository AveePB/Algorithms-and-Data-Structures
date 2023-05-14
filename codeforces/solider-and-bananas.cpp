#include <bits/stdc++.h>

using namespace std; 

int base_banana_price{}, money{}, n_bananas{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> base_banana_price >> money >> n_bananas; 

    int cost = 0; 
    for(int i=1; i<=n_bananas; i++)
        cost += base_banana_price * i; 

    if (money - cost < 0)
        cout << (cost - money) << endl; 
    else 
        cout << 0 << endl; 

    return 0; 
}
