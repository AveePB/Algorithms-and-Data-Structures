#include <bits\stdc++.h> 

using namespace std; 

unsigned int zeros{}, ones{}; 
string players{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> players; 

    for (char player: players){
        if (player == '0'){
            ones = 0; 
            zeros++; 
        }
        else{
            zeros = 0; 
            ones++; 
        }

        if (ones == 7 || zeros == 7){
            cout << "YES" << endl; 
            exit(0); 
        }
    }

    cout << "NO" << endl; 


    return 0; 
}
