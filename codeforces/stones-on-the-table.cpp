#include<bits/stdc++.h>

using namespace std; 

unsigned int n_changes = 0; 
unsigned int n_stones = 0; 
string stones = ""; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n_stones; 
    cin >> stones; 
    

    for(int i=1; i<n_stones; i++){
        if (stones[i-1] == stones[i])
            n_changes++; 
    }

    cout << n_changes << endl; 
    
    
    return 0; 
}
