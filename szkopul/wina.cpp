#include <bits/stdc++.h>
using namespace std; 

int n{}, k{}, old{INT_MAX}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);

    cin >> n >> k; 

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            int cost{}, curr{}, pos{};
            cin >> curr;
            
            pos = (i-j)+1;
            cost = pos * j; 
            
            if(cost <= k && curr < old)
                old = curr;
        }
    }
    cout << old << endl; 
    
    return 0; 
}