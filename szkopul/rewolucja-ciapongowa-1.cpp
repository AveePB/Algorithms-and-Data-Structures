#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 1e6 + 7; 
vector<long long> sum_pref(MAXN); 
int n{}, m{}, x{}, y{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n >> m;

    for(int i=1; i<n; i++){
        cin >> sum_pref[i]; 
        sum_pref[i] += sum_pref[i-1];
    }

    while(m--){
        int c1{}, c2{}; 
        cin >> x >> y;
        c1 = min(x, y); 
        c2 = max(x, y); 
        
        cout << sum_pref[c2-1] - sum_pref[c1-1] << endl;
    }
    
    return 0; 
}
