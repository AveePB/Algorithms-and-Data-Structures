#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base:: sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    unsigned int weight = 0; 
    cin >> weight; 

    if (weight % 2 == 0 && weight > 2)
        cout << "YES" << endl; 
    else 
        cout << "NO" << endl; 

    return 0; 
}
