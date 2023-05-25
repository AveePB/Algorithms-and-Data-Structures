#include <bits/stdc++.h>

using namespace std; 

int t{}, n{}, m{}, k{}; 

bool move(int x, int y, int c){
    if(x == n && y == m) return c == k; 
    if(x < n) return move(x+1, y, c+y); 
    if(y < m) return move(x, y+1, c+x); 
    
    return 0; 
}

int main(){
    cin >> t; 

    while(t--){
        cin >> n >> m >> k; 
        if(move(1, 1, 0))
            cout << "YES" << endl; 
        else 
            cout << "NO" << endl; 
    } 

    return 0; 
}

