#include <bits/stdc++.h>

using namespace std;

int max_lvl{};

void next_element(pair<int, int> left, pair<int, int> mid, pair<int, int> right, int curr_lvl){    
    if(curr_lvl++ > max_lvl) return;

    pair<int, int> new_mid; 

    new_mid = {
        left.first + mid.first, 
        left.second + mid.second
    }; 
    
    next_element(left, new_mid, mid, curr_lvl); 
    
    cout << mid.first << '/' << mid.second << ' '; 
    
    new_mid = {
        mid.first + right.first, 
        mid.second + right.second
    };

    next_element(mid, new_mid, right, curr_lvl); 
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> max_lvl;

    cout << "0/1 "; 
    next_element({0, 1}, {1, 1}, {1, 0}, 1);
    cout << "1/0";
    return 0;
}
