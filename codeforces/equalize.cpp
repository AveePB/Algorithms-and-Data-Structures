#include <bits/stdc++.h>
 
using namespace std; 
 
vector<int> zeros; 
vector<int> ones; 
 
string a{}, b{}; 
int n{}, c{}, p{}; 
 
//a to change 
//b the key 
 
int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 
 
    cin >> n >> a >> b;  
 
    for(int i=0; i<n; i++){
        if(a[i] == b[i])
            continue; 
        
        if(a[i+1] == b[i] && a[i] == b[i+1])
            i += 1; 
        c += 1; 

    } 
  
    cout << c << endl; 
    
    return 0; 
}
