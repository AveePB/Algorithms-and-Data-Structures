#include <bits/stdc++.h>

using namespace std; 

int n{}, m{}, q{}, curr_q{}, c{}; 

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> q;
            if(q == 0)
                continue;

            if(c == 0)
                curr_q = q;

            if(curr_q != q)
                c--; 
            else 
                c++;
        }
    }
    cout << curr_q << endl;
    return 0; 
}
