#include <bits/stdc++.h>
using namespace std; 

const int MAX_N = 5e5+7;

int n=0, m=0, ptr=1, car_height=0;
int heights[MAX_N];

map<int, int> last_idx;

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;

    cin >> heights[0];
    for(int i=1; i<n; i++){
        cin >> heights[ptr];
        heights[ptr] = min(heights[ptr], heights[ptr-1]);
        
        last_idx[heights[ptr]] = i;
        if(heights[ptr-1] > heights[ptr]) ptr++;
    }
    
    for(int i=0; i<m; i++){
        cin >> car_height;
        int ans = -1;
        
        for(int height: heights) {
            if(height <= car_height) break;
            ans = last_idx[height];
        }
        cout << ans+1 << ' ';
    }
    return 0; 
}
