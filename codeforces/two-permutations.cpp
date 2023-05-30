#include<bits/stdc++.h>
using namespace std; 
 
int n, a, b, t; 
int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
 
    cin >> t; 
    while (t--){
        cin >> n >> a >> b; 
        if(a == b && n == a && n == b)
            cout << "Yes\n";
        else if (n-1 > (a+b))
            cout << "Yes\n"; 
        else 
            cout << "No\n";  
    }
    
    return 0; 
}
