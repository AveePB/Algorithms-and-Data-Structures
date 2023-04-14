#include <bits/stdc++.h>

using namespace std; 

int n{}, m{}; 
map<int, string> results; 
void test(); 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n; 

    while(n--){
        cin >> m; 
        if(m > 1099){
            cout << "yes" << endl; 
            continue; 
        }
        
        if(results.find(m) != results.end()){
            cout << results[m] << endl;
            continue; 
        }

        test(); 
    }

    return 0; 
}

void test(){
    for(int i=0; i<=m; i++){
        for(int j=0; j<=m; j++){
            if(m == (i*11 + j*111)){
                cout << "YES" << endl; 
                results[m] = "YES"; 
                return; 
            }
        }
    }
    cout << "NO" << endl;
    results[m] = "NO";  
}
