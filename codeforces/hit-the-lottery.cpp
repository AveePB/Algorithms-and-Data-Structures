#include <bits/stdc++.h>

using namespace std; 

vector<int> bills = {100, 20, 10, 5, 1}; 

int n{}, o{}; 


int main(){
    cin >> n; 

    for(int i=0; i<5; i++){
        o += n / bills[i]; 
        n %= bills[i]; 
    }

    cout << o << endl; 


    

    return 0; 
}
