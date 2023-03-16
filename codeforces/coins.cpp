#include <bits/stdc++.h>

using namespace std; 

int n{}, m{}; 

int main(){
    cin >> n; 
    
    for(int i=n; i>0; i--){
        if(m%i == 0){
            cout << i << " "; 
            m = i; 
        }
    }

    return 0; 
}
