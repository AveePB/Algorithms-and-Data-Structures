#include <bits/stdc++.h>

using namespace std; 

unsigned int limak_weight{}, bob_weight{};

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> limak_weight >> bob_weight; 

    for(int i=1; i<100; i++){
        limak_weight *= 3; 
        bob_weight *=2; 

        if (limak_weight > bob_weight){
            cout << i << endl; 
            break; 
        }
    }

    return 0; 
}
