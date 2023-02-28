#include <bits/stdc++.h>
using namespace std;

long long n{}, k{}, ans{}; 

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
	cin >> n >> k;

	if(k >= 1) ans += 1;
	if(k >= 2) ans += n*(n-1)/2;
	if(k >= 3) ans += n*(n-1)*(n-2)/6*2;
	if(k >= 4) ans += n*(n-1)*(n-2)*(n-3)/24*9;
	
    cout << ans;
	
    return 0;
}
