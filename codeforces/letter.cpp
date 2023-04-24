#include <bits/stdc++.h> 

using namespace std; 

int c1{}, c2{}; 
string s{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> s; 

    for(int i=0; i<int(s.length()); i++){
        if(int(s[i]) > 91)
            c1++; 
        else
            c2 = min(c2+1, c1) ;
    } 
    cout << c2 << endl; 

    return 0; 
}
