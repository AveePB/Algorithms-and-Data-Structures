#include <bits/stdc++.h>

using namespace std; 
const int R{10}, BG{1}; 

int n_tests{}, n{}; 
string r1{}, r2{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n_tests; 
    while (n_tests--){
        int s1{}, s2{};
        cin >> n; 
        cin >> r1 >> r2; 
        
        for(int i=0; i<n; i++){
            if(r1[i] == 'R')
                s1 += R; 
            else 
                s1 += BG; 
            
            if(r2[i] == 'R')
                s2 += R; 
            else 
                s2 += BG;
        
            if(s1 != s2)
                break;  
        }

        if(s1 == s2)
            cout << "YES" << endl; 
        else 
            cout << "NO" << endl; 

    }
    
    return 0; 
}
