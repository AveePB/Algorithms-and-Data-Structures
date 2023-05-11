#include <bits/stdc++.h>
 
using namespace std;

int n=0; 

int get_set_bits(int n){
    if (!n)
        return 0; 

    return (n&1) + get_set_bits(n >> 1); 
}


int main() {
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n; 
    cout << get_set_bits(n) << endl; 
}
