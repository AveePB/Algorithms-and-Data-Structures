#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 1e6+7;
vector<int> v(MAXN);

int n{}, x{}, num{};

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> num; 
        v[num]++; 
    }

    if(v[1] < 2)
        x = (2-v[1]); 
    
    cout << x << endl; 
    cout << 2 << endl; 
    cout << "1 2" << endl;

    return 0; 
}
