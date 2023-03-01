#include <bits/stdc++.h>

using namespace std; 

int k{}, a{}, b{}, u{}, v{}; 
string s; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> k >> a >> b; 
    cin >> s; 

    if(int(s.length()) > b*k || int(s.length()) < a*k){
        cout << "No solution" << endl; 
        return 0; 
    }

    for(;k>0;k--){
        v = int(s.length()) - u;
        v /= k; 
        cout << s.substr(u, v) << endl; 
        u += v; 
    }


    return 0; 
}
