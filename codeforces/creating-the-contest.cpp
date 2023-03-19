#include <bits/stdc++.h>

using namespace std; 

vector<long long> dp; 
int n{}, c{}; 



int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n; 

    for(int i=0; i<n; i++){
        long long k{}; 
        cin >> k;
        dp.push_back(k);  
    }

    for(int i=0; i<n; i++){
        int curr_c{i};

        while(curr_c+1 < n && dp[curr_c+1] <= dp[curr_c]*2) 
            curr_c++; 
        
        c = max(c, curr_c-i + 1); 
        i = curr_c; 
    }

    cout << c << endl; 

    
}
