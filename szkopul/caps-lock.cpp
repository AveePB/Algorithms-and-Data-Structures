#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 1e6 + 7; 
const long long MOD = 1e9 + 7; 
const long long P = 199;

vector<long long> pow_p(MAXN), hashes(MAXN); 
string text{}, key{}, ans{};
int n{}, m{}; 

long long get_hash(long long idx1, long long idx2){
    idx1 += 1; 
    idx2 += 1; 

    long long res = (hashes[idx2] - hashes[idx1-1] + MOD) % MOD; 
    return (res * pow_p[n-idx1+1]) % MOD; 
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> text >> key;
    n = int(text.length()); 
    m = int(key.length()); 
    
    ans = text; 
    pow_p[0] = 1;

    for(int i=1; i<=n; i++)
        pow_p[i] = (pow_p[i-1] * P) % MOD;

    long long key_hash{};
    for(int i=0; i<m; i++)
        key_hash = (key_hash + key[i] * pow_p[i]) % MOD; 
    key_hash = (key_hash * pow_p[n]) % MOD; 

    for(int i=0; i<n; i++)
        hashes[i+1] = (hashes[i] + pow_p[i] * text[i]) % MOD;
    
    for(int i=m-1; i<n; i++)
        if(get_hash(i-m+1, i) == key_hash)
            for(int j=0; j<m; j++){
                if(ans[i-j] <= 'Z') 
                    break;
                ans[i-j] -= 32;
            }
                       
    cout << ans << endl; 
    return 0; 
}
