#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    long long int x, y, n, i, j;
    cin >> n;
    for(i=1; i <= n; i++){
        cin >> x; 
        y = sqrt(x);
        for(j=2; j*j<y; j++)
            if(x%j==0) break;
            if(j*j > y && y*y == x && x > 1) 
                 cout << ("YES\n");
            else 
                cout << ("NO\n");
    }
}
