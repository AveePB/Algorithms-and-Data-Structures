#include <bits/stdc++.h>

using namespace std; 

const int INF = 1000000007;

int t{}, n{}, m{}; 

int main(){

    cin >> t; 

    while(t--){
        cin >> n >> m;

        vector<int> c(m+1), k(n+1), dp(n+2);
        vector<bool> sold(m);  
        
        for(int i=1; i<=n; i++)
            cin >> k[i];  
 
        for(int i=1; i<=m; i++)
            cin >> c[i];

        c[0] = INF;  
        sort(k.begin(), k.end()); 
        
        for(int i=1; i<=n; i++){
            int jj = 0; 

            for(int j=1; j<k[i]; j++){
                if(sold[j])
                    continue;

                if(c[j] <= c[jj])
                    jj = j;  
            }

            if(c[k[i]] < c[jj]){
                dp[i] = c[k[i]];  
            }
            else{
                dp[i] = c[jj]; 
                sold[jj] = true;
            }
            
             
        }

        for(int i=1; i<=n; i++){
            cout << i << ". GUEST GETS " << dp[i] << endl; 
        } 
    }
     

    return 0; 
}
