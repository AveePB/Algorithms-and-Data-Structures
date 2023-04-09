#include <bits/stdc++.h>

using namespace std;

vector<int> nums; 
string equation = ""; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> equation; 

    for(char c: equation){
       if (int(c) >= 48 && int(c) <=57)
            nums.push_back(int(c)); 
    }

    sort(nums.begin(), nums.end());

    cout << char(nums[0]); 
    for(int i=1; i<nums.size(); i++){
        cout << "+" << char(nums[i]); 
    }


    return 0; 
} 
