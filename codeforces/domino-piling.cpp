#include <bits/stdc++.h> 

using namespace std; 

unsigned int width{}, height{}; 

int main(){    
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 
    
    cin >> width >> height; 

    cout << (width * height) / 2 << endl; 

    return 0; 
}
