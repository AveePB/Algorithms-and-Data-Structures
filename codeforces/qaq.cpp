#include <bits/stdc++.h>

using namespace std; 

string s{}; 
vector<int> idx; 
vector<int> dp; 
int a{}, q{}, o{}; 

int main(){

    cin >> s;
    dp.resize(int(s.length())+1); 

    for(int i=0; i<int(s.length()); i++){
        dp[i+1] = dp[i]; 
        
        if(s[i] == 'A'){
            idx.push_back(i);
            continue; 
        }
        
        if(s[i] == 'Q')
            dp[i+1] += 1;
    } 

    for(auto i: idx){
        int l = dp[i]; 
        int r = dp[dp.size()-1] - dp[i];

        o +=  l*r;  
    }

    cout << o << endl; 


    return 0; 
}
