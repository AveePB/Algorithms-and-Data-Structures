#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7; 
vector<long long> sum_pref(MAXN);
int t{}, n{}, q{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> t; 
    while(t--){
        vector<long long> steps;  
        long long a{}, k{}, last_a{}; 
        cin >> n >> q; 
        
        for(int i=0; i<n; i++){
            cin >> a;
            sum_pref[i+1] = sum_pref[i] + a;
            last_a = max(a, last_a); 
            steps.push_back(last_a);  
        }

        for(int i=0; i<q; i++){
            cin >> k; 

            int l=-1, r=n;
            while(r-l > 1){
                int mid = (l+r)/2;
                if(steps[mid] > k)
                    r = mid; 
                else 
                    l = mid; 
            }
            cout << sum_pref[l+1] << ' '; 
        }
        cout << '\n';
    }
}
