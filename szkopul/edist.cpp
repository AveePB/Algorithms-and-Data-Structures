#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 1e3; 

vector<vector<int>> dp(MAXN, vector<int>(MAXN));
string s1{}, s2{};
int t{};

void test(); 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    for(int i=0; i<MAXN; i++){
        dp[0][i] = i; 
        dp[i][0] = i; 
    }

    cin >> t; 
    while(t--)
        test();

    return 0; 
}

void test(){
    cin >> s1 >> s2;

    for(int i=0; i<int(s1.length()); i++){
        for(int j=0; j<int(s2.length()); j++){
            if(s1[i] == s2[j]){
                dp[i+1][j+1] = dp[i][j];
                continue; 
            }
            
            dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1]);
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            dp[i+1][j+1] += 1;
        } 
    }

    cout << dp[int(s1.length())][int(s2.length())] << endl;
}
