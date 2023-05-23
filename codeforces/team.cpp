#include <bits/stdc++.h> 

using namespace std; 

unsigned int n_problems = 0; 
unsigned int output = 0; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n_problems; 

    for(int i=0; i<n_problems; i++){
        bool a{}, b{}, c{}; 
        cin >> a >> b >> c; 

        output += (a+b+c >= 2);
    }

    cout << output << endl; 

    return 0; 
}
