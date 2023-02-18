#include<bits/stdc++.h>
using namespace std;

constexpr long long MOD_A = 1e9+7; 
constexpr long long MOD_B = 1e9+9;//1e9+7, 1e9+9, 1e9+123, 1e9+321...
constexpr long long P_A = 31;
constexpr long long P_B = 59; //P must be the prime number
constexpr int N = 1e3+7;

long long prefHashA[N], prefHashB[N];
long long powA[N], powB[N];

void init(string t){
    //WE COMPUTE THE POWERS
    powA[0] = 1, powB[0] = 1;
    for(int i=1; i<N; i++){
        powA[i] = (powA[i-1] * P_A) % MOD_A;
        powB[i] = (powB[i-1] * P_B) % MOD_B;
    }

    //WE COMPUTE PREFIX HASHES OF THE TEXT
    prefHashA[0] = 0, prefHashB[0] = 0;
    for(int i=1; i<=t.size(); i++){
        prefHashA[i] = (prefHashA[i-1] + (long long)t[i-1] * powA[i-1]) % MOD_A;
        prefHashB[i] = (prefHashB[i-1] + (long long)t[i-1] * powB[i-1]) % MOD_B;
    }
}

pair<long long, long long> getHash(string s){
    pair<long long, long long> h = {0, 0};
    for(int i=0; i<s.size(); i++){
        h.first = (h.first + (long long)s[i] * powA[i]) % MOD_A;
        h.second = (h.second + (long long)s[i] * powB[i]) % MOD_B;
    }
    return h;
}


bool isDetected(string text, pair<long long, long long> sHash, int n){
    for(int i=1; i<=(text.size()-n)+1; i++){
        int j = i + n - 1;
        //WE GET THE HASH
        long long subHashA = prefHashA[j] - prefHashA[i-1];
        long long subHashB = prefHashB[j] - prefHashB[i-1];
        subHashA = (subHashA + MOD_A) % MOD_A;
        subHashB = (subHashB + MOD_B) % MOD_B;

        if(subHashA == sHash.first && subHashB == sHash.second)
            return true;
        
        //We multiply the hash by const 
        //because we are moving up
        sHash.first = (sHash.first + MOD_A) % MOD_A;
        sHash.second = (sHash.second + MOD_B) % MOD_B;

        sHash.first = (sHash.first * P_A) % MOD_A;
        sHash.second = (sHash.second * P_B) % MOD_B;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    pair<long long, long long> myHash; string s{}, text{};
    cin >> text >> s; text = text;
    init(text); myHash = getHash(s);

    cout << isDetected(text, myHash, s.size());

    return 0;
}
