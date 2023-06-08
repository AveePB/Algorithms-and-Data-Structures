#include <bits/stdc++.h>

using namespace std; 

string word = ""; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> word; 

    word[0] = toupper(word[0]); 

    cout << word << endl; 

    return 0; 
}
