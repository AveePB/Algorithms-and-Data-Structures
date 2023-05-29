#include <bits/stdc++.h>
 
using namespace std;

int n{}, m{}, moves{}; 
// n <- initial value 
// m <- target value 

int main() {
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n >> m; 

    while(n < m){
        if(!(m&1))
            m /= 2; 
        else 
            m++; 
        moves++; 
    }


    cout << moves + abs(n - m) << endl; 
}
