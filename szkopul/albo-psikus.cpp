#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int n{}, c[N], curr_even{}, curr_odd{};
long long ans{};

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n;
    c[0] = 0;
    
    //O(N)
    for(int i=1; i<=n; i++){
        cin >> c[i];
        c[i] %= 2;
        c[i] += c[i-1];
    }

    //O(N)
    for(int i=0; i<=n; i++){
        if(c[i] % 2 == 1){
            ans += curr_odd;
            curr_odd++;
        }
        else{
            ans += curr_even;
            curr_even++;
        }
    }

    cout << ans;
    return 0;
}
