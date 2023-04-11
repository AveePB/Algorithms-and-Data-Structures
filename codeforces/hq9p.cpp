#include <bits/stdc++.h>

using namespace std; 

string instructions{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> instructions; 

    for(char instruction: instructions){
        if (instruction == 'H' || instruction == 'Q' || instruction == '9'){
            cout << "YES" << endl; 
            exit(0);  
        }

    }
    cout << "NO" << endl; 
    
    return 0; 
}
