#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+7;
int n{}, k{}, p{}, ans{INT_MAX}; 
vector<int> a(MAXN), b(2*MAXN);

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    
    cin >> n >> k >> p;
    for(int i=0; i<n; i++) cin >> a[i]; 
    for(int i=0; i<k; i++) cin >> b[i]; 
    
    sort(a.begin(), a.begin()+n); 
    sort(b.begin(), b.begin()+k);

    for(int q=0; q+n <= k; q++){
        int dist{}; 
        for(int i=0; i<n; i++) 
            dist = max(dist, abs(a[i]-b[i+q]) + abs(p-b[i+q]));  
        ans = min(ans, dist); 
    }
    
    cout << ans; 

    return 0; 
}
