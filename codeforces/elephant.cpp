#include <bits/stdc++.h>

using namespace std; 

unsigned int house_coordinate{};
unsigned int n_steps{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> house_coordinate; 

    for(int i=5; i>0; i--){
        if (house_coordinate % i == 0){
            n_steps += (house_coordinate / i); 
            cout << n_steps << endl; 
            break;
        }
        else{
            n_steps += house_coordinate / i;
            house_coordinate %= i; 
        }
    }

    return 0; 
}
