#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+7;

int n{}, m{}, d{}, ans[N]{};
vector<int> floors(N);
bool blocked[N]{};

int simulate(){
    for(int i=n; i>0; i--){
        if(blocked[i] == false && d <= floors[i]){
            blocked[i] = true;
            n = i-1;
            return i;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);    
    cin >> n >> m;
    
    blocked[n+1] = true;
    floors[0] = 1e9+7;

    for(int i=1; i<=n; i++){
        cin >> floors[i];
        floors[i] = min(floors[i], floors[i-1]);
    }

    for(int i=1; i<=m; i++){
        cin >> d;
        ans[i] = simulate();
    }
    cout << ans[m];
    return 0;
}
