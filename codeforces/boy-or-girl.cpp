#include <bits/stdc++.h> 

using namespace std; 

string nickname = ""; 

set<char> nickname_chars; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> nickname; 

    for(char c: nickname)
        nickname_chars.insert(c); 

    if(nickname_chars.size() % 2 == 0)
        cout << "CHAT WITH HER!" << endl; 
    else 
        cout << "IGNORE HIM!" << endl;

    return 0; 
}
