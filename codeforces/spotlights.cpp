#include <bits/stdc++.h>

using namespace std; 

vector<vector<int>> sum_hori; 
vector<vector<int>> sum_vert; 
vector<vector<int>> area; 

int n_rows{}, n_cols{}, c{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n_rows >> n_cols; 
    
    area.resize(n_rows); 
    
    for(int i=0; i<n_rows; i++){
        area[i].resize(n_cols); 
        for(int j=0; j<n_cols; j++)
            cin >> area[i][j];
    }

    sum_hori.resize(n_rows); 
    for(int i=0; i<n_rows; i++){
        sum_hori[i].resize(n_cols+1); 
        for(int j=1; j<=n_cols; j++)
            sum_hori[i][j] = sum_hori[i][j-1] + area[i][j-1];  
    }

    sum_vert.resize(n_rows+1); 
    sum_vert[0].resize(n_cols); 

    for(int i=1; i<=n_rows; i++){
        sum_vert[i].resize(n_cols); 
        for(int j=0; j<n_cols; j++)
            sum_vert[i][j] = sum_vert[i-1][j] + area[i-1][j]; 
    }

    for(int i=0; i<n_rows; i++){
        for(int j=0; j<n_cols; j++){
            if(area[i][j] == 1) 
                continue; 
            
            c += min(sum_hori[i][j] - sum_hori[i][0], 1);
            c += min(sum_hori[i][n_cols] - sum_hori[i][j], 1);
            c += min(sum_vert[i][j] - sum_vert[0][j], 1); 
            c += min(sum_vert[n_rows][j] - sum_vert[i][j], 1);
        }
    }
    
    cout << c << endl; 

    return 0; 
}
