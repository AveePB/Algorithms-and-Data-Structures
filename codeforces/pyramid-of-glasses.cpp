#include <bits/stdc++.h>

using namespace std; 

const int N = 10 + 7;
const int L = 1024;  

vector<vector<int>> v(N, vector<int>(N)); 

int n{}, t{}, q{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n >> t;
    v[1][1] = t * L;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(v[i][j] >= L){
                int x = v[i][j] - L;
                q++; 

                v[i+1][j] += x / 2; 
                v[i+1][j+1] += x / 2;
            }   
        } 
    }

    cout << q << endl; 

    return 0; 
}
