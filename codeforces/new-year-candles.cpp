#include <bits/stdc++.h>
 
using namespace std;

int a{}, b{}, n_hours{}; 

int main() {
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> a >> b;    
    n_hours += a;

    while(a/b){
        int rest = a % b; 
        n_hours += a/b; 

        a = a/b + rest;     
    } 


    cout << n_hours << endl; 

}
