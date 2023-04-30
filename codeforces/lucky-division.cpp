#include <bits/stdc++.h>

using namespace std; 

unsigned int n = 0; 

vector<int> lucky_numbers; 

bool is_lucky(string num){
    for(char digit: num){
        if (digit != '7' && digit != '4')
            return false; 
    }
    return true; 
}


int main(){ 
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n; 

    for(int i=1; i<=n; i++){
        string str_num = to_string(i); 
        if (is_lucky(str_num))
            lucky_numbers.push_back(i);  
    }

    for(int lucky_num: lucky_numbers){
        if (n % lucky_num == 0){
            cout << "YES" << endl; 
            exit(0); 
        }
    }

    cout << "NO" << endl; 

    return 0;
}
