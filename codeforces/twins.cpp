#include <bits/stdc++.h>

using namespace std; 

unsigned int n_coins = 0;
unsigned int output = 0; 

unsigned int total_coin_val = 0; 
unsigned int stolen_coin_val = 0; 
unsigned int n_stolen_coins = 0; 

vector<int> coin_values; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n_coins; 
    coin_values.resize(n_coins); 

    for(int i=0; i<n_coins; i++){
        cin >> coin_values[i]; 
        total_coin_val += coin_values[i]; 
    }  

    sort(coin_values.begin(), coin_values.end()); 
    
    for(int i=n_coins; i>0; i--){
        stolen_coin_val += coin_values[i-1]; 
        n_stolen_coins ++; 

        if ((total_coin_val - stolen_coin_val) < stolen_coin_val){
            break;
        }
    }

    cout << n_stolen_coins << endl; 


    return 0; 
}
