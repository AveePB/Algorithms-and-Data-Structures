#include <bits/stdc++.h>

using namespace std; 

unsigned int n_cols = 0; 
vector<int>cols; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n_cols; 
    cols.resize(n_cols);

    for(int i=0; i<n_cols; i++)
        cin >> cols[i]; 

    sort(cols.begin(), cols.end()); 

    for(int i=0; i<n_cols; i++)
        cout << cols[i] << " "; 

    return 0; 
}
