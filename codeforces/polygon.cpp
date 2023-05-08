#include <bits/stdc++.h>

using namespace std; 

vector<vector<bool>> b;
vector<string> p;
int t{}, n{}; 

void check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(p[i][j] == '0' || b[i][j])
                continue; 

            if(!(p[i][j+1] == '1' || p[i+1][j] == '1')){
                cout << "NO" << endl; 
                return; 
            }

            b[i][j] = true; 
        }
    }
    cout << "YES" << endl;  
}

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> t; 

    while(t--){
        cin >> n; 
        b.resize(n); 
        p.resize(n+1); 
    
        for(int i=0; i<n; i++){
            cin >> p[i]; 
            p[i] += '1';
            p[n] += '1';

            b[i].resize(n);  
        }
        check();

        b.clear(); 
        p.clear(); 
    } 

    
    
     
    


    return 0; 
}
