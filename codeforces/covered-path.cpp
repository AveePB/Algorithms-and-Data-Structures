#include <bits/stdc++.h>
using namespace std;

int v1{}, v2{}, t{}, d{}, ans{};

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
	cin >> v1 >> v2 >> t >> d; 

	t -= 2; 

	int curr_speed1 = v1; 
	int curr_speed2 = v2; 

	while (t--){
		if(curr_speed1 > curr_speed2){
			v2 += curr_speed2 + d;
			curr_speed2 += d; 
		} 
		else{
			v1 += curr_speed1 + d;
			curr_speed1 += d; 
		}
	}
	
	cout << v1 + v2 << endl; 
	

	
    return 0;
}
