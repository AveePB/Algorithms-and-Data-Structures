#include <bits/stdc++.h>

using namespace std; 

priority_queue<int> c; 
int n{}, t{}; 

int main(){
    cin >> t; 

    while(t--){
        int p1{}, p2{}; 
        cin >> n;

        for(int i=0; i<n; i++){
            int c1{}; 
            cin >> c1; 
            c.push(c1); 
        } 

        while(!c.empty()){
            int candy = c.top(); 
            c.pop(); 

            if(p1 > p2)
                p2 += candy; 
            else 
                p1 += candy; 
        }

        if(p1 == p2)
            cout << "YES" << endl; 
        else 
            cout << "NO" << endl; 

    }

    return 0; 
}
