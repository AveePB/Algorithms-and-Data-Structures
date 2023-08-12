#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 1e6+7; 
const int MAX_VAL = 1e4+7; 

vector<long long> v(MAXN), sum_pref(MAXN), counter(MAX_VAL);
long long ans{}; 
int n{}, k{};  

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> k; 

    for(int i=1; i<=n; i++)
        cin >> v[i];

    sort(v.begin(), v.begin()+n+1);

    for(int i=1; i<=n; i++){
        sum_pref[i] = sum_pref[i-1] + v[i]; 
        for(int j=v[i-1]+1; j<=v[i]; j++){
            counter[j] = counter[j-1];
        }
        long long temp = counter[v[i]] - counter[max(v[i]-k-1, 0LL)]; 
        ans += temp * k; 
        ans += v[i]*(i-1-temp) - sum_pref[i-1-temp]; 
        
        counter[v[i]]++; 
    }          

    cout << ans << endl;     
    return 0; 
}
