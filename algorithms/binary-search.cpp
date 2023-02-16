#include<bits/stdc++.h>
using namespace std; 

const int MAXN = 1e3+7; 
vector<int> v(MAXN); 
int n{}, m{};

//o(logN)
int binarySearch(int val){
    int l = 0, r = n;

    while (r-l > 1){
        int mid = (l+r)/2; 
        if(v[mid] > val)
            r = mid; 
        else 
            l = mid;     
    }
     
    return (v[l] == val);
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
    
    cin >> n >> m; 
    for(int i=0; i<n; i++)
        cin >> v[i];

    for(int i=0; i<m; i++){
        int val; 
        cin >> val;

        cout << binarySearch(val) << '\n'; 
    }
    
    return 0; 
}
