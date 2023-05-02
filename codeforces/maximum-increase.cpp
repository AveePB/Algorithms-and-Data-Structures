#include <bits/stdc++.h>
 
using namespace std; 
 
int n{}, p{}, a{}, c{}, c_max{}; 
 
int main(){
 
    cin >> n; 
 
    for(int i=0; i<n; i++){
        cin >> a; 
 
        if(a > p){
            p = a; 
            c++; 
        } 
        else{
            c_max = max(c_max, c);
            
            p = a;   
            c = 1;
        } 
    }
 
    cout << max(c, c_max) << endl; 
     
 
    return 0; 
}
