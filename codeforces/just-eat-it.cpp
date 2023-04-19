#include <bits/stdc++.h>

using namespace std; 

int t{}, n{}, c{};

void test(); 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 
    
    cin >> t; 
    while(t--)
        test(); 
     
    return 0; 
}

void test(){
    
    cin >> n;
    long long sum{}; 
    vector<long long> a(n); 
    
    for(int i=0; i<n; i++)
        cin >> a[i]; 

    for(int i=0; i<n; i++){
        sum += a[i]; 
        if(sum <= 0){
            cout << "NO" << endl; 
            return; 
        }
    }
    sum = 0; 
    for(int i=n-1; i>=0; i--){
        sum += a[i]; 
        if(sum <= 0){
            cout << "NO" << endl; 
            return; 
        }
    }
    cout << "YES" << endl; 
}
