#include <bits/stdc++.h>

using namespace std; 

long long n{}, m1{LONG_LONG_MAX}, m2{LONG_LONG_MIN}, c1{1}, c2{1};

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n; 

    while(n--){
        long long f{};
        cin >> f; 

        if(f > m2){
            m2 = f; 
            c2 = 1; 
        }
        else if(f == m2){
            c2++; 
        }

        if(f < m1){
            m1 = f; 
            c1 = 1; 
        }
        else if(f == m1){
            c1++; 
        }
    }

    if(m1 != m2)
        cout << m2-m1 << " " << c1*c2 << endl;
    else 
        cout << "0 " << c1*(c1-1)/2 << endl;  

    return 0; 
}
