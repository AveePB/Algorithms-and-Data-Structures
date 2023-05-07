#include <bits/stdc++.h>

using namespace std; 

 string str1{}, str2{};
signed int output = 0; 

int main(){
    ios::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 
   
    cin >> str1 >> str2; 

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper); 
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    for(int i=0; i<str1.size(); i++){
        if (int(str1[i]) < int(str2[i])){
            output = -1; 
            break; 
        }
        else if (int(str1[i]) > int(str2[i])){
            output = 1;  
            break; 
        }
    }

    cout << output << endl; 

    return 0; 
}
