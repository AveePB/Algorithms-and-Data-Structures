#include <bits/stdc++.h>

using namespace std; 

signed int x_out{}, y_out{}, z_out{};
unsigned int n_points{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n_points; 

    for(int i=0; i<n_points; i++){
        int x{}, y{}, z{}; 
        cin >> x >> y >> z; 
        x_out += x; 
        y_out += y; 
        z_out += z; 
    }

    if ((x_out == 0) && (y_out == 0) && (z_out == 0))
        cout << "YES" << endl; 
    else 
        cout << "NO" << endl; 


    return 0; 
}
