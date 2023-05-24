#include <bits/stdc++.h>

using namespace std; 

long double n{}, m{}, a{};
long long int result{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n >> m >> a; 

    result = ceil(n/a) * ceil(m/a); 

    cout << result << endl; 


    return 0; 
}
