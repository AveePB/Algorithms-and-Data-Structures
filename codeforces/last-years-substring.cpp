#include <bits/stdc++.h>

using namespace std; 

const string target = "2020"; 

int n{}, t{};
string s{}; 

int main(){
    cin >> t; 
    while(t--){
        string curr_s{}; 
        int z = 100000;
        cin >> n >> s; 

        for(int i=0; i<4; i++){
            if (s[i] != target[i]){
                z = i; 
                break;  
            }
            curr_s += s[i]; 
        }

        for(int i=n-(4-z); i<n; i++)
            curr_s += s[i]; 

        if(curr_s == target)
            cout << "YES" << endl;   
        else 
            cout << "NO" << endl; 
    }
     

    return 0; 
}
