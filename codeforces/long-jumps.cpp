#include <bits/stdc++.h>

using namespace std; 

map<int, long long> dp; 
vector<int> a; 
int t{}, n{};


long long jump(int i, long long p); 
void test(); 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> t; 

    while(t--){
        dp.clear(); 
        a.clear(); 
        test();
    }
        

    return 0; 
}

long long jump(int i, long long p){
    if(i > n)
        return p; 
    
    if(dp.find(i) == dp.end())
        dp[i] = jump(i+a[i], p+a[i]); 
    
    return dp[i];     
} 


void test(){
    long long p{}; 
   
    cin >> n; 
    a.resize(n+1); 

    for(int i=1; i<=n; i++)
        cin >> a[i]; 

    for(int i=1; i<=n; i++){
        if(dp.find(i) == dp.end())
            dp[i] = jump(i, 0); 
        p = max(dp[i], p);
    }
    cout << p << endl; 
}
