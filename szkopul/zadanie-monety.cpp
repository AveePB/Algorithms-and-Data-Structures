#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 1e6 + 7; 
const int O = 79;

vector<long long> sum_pref(MAXN); 
map<long long, int> m; 
int n{}, k{}, res{}; 
string s{};

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n >> k >> s; 

    for(int i=1; i<=n; i++){
        sum_pref[i] = 1;  
        if(int(s[i-1]) != O)
            sum_pref[i] = -k;   
        sum_pref[i] += sum_pref[i-1];   
    }
    
    for(int i=0; i<=n; i++)
        if(m.find(sum_pref[i]) == m.end())
            m[sum_pref[i]] = i;

    for(int i=0; i<=n; i++){
        int j = m[sum_pref[i]];
        res = max(res, i-j); 
    }

    cout << res << endl; 
     
    return 0; 
}