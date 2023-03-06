#include <bits/stdc++.h>

using namespace std; 

const pair<int, int> THE_MIDDLE = {3, 3}; 
pair<int, int> point = {-1, -1};

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    for(int row=1; row<=5; row++){
        for(int column=1; column<=5; column++){
            int val = 0; 
            cin >> val; 

            if (val == 1){
                point.first = row; 
                point.second = column; 
            }
        }
    }

    cout << abs(THE_MIDDLE.first - point.first) + abs(THE_MIDDLE.second - point.second) << endl; 

    return 0; 
}
