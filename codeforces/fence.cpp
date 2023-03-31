#include <bits/stdc++.h>

using namespace std; 

vector<int> sum_pref; 
int min_val{20000000}, min_idx{}; 
int n{}, k{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n >> k; 
    sum_pref.resize(n+1); 

    for(int i=1; i<sum_pref.size(); i++){
        int w{}; 
        cin >> w; 
        sum_pref[i] = sum_pref[i-1] + w; 
    }

    for(int i=1; i<=(n-k)+1; i++){
        int val = sum_pref[i+(k-1)] - sum_pref[i-1]; 
        if(val < min_val){
            min_val = val; 
            min_idx = i; 
        }
    }

    cout << min_idx << endl; 

    return 0; 
}
