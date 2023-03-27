#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int t{}; 
    cin >> t; 

    while (t--){
        int n{}, p1{}, p2{}; 
        cin >> n; 

        for(int i=0; i<n; i++){
            int a{}; 
            cin >> a; 
            a = abs(a);

            p1 += (a % 2 == 1);
            p2 += (a % 2 == 0); 
        }

        if(p1 % 4 == 2)
            cout << "Bob\n"; 
        else if((p2 % 2 == 0) && (p1%4 == 1))
            cout << "Bob\n"; 
        else 
            cout << "Alice\n";
    }
    
    return 0; 
}
