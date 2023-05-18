#include <bits/stdc++.h>

using namespace std; 

int t{}, n{}; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);
    
    cin >> t; 
    while(t--){
        int min_idx{0}, max_idx{0}; 
        int l{}, r{}, add{}, o{}; 
        vector<int> nums;

        cin >> n;  
        nums.resize(n); 

        for(int i=0; i<n; i++){
            cin >> nums[i];

            if(nums[i] == 1)
                min_idx = i; 
            else if(nums[i] == n)
                max_idx = i;  
        }

        l = min(min_idx, max_idx); 
        r = max(min_idx, max_idx);
        add = r-l;   

        l = min(abs(n-l), l+1); 
        r = min(abs(n-r), r+1); 


        o = min((l+add), (r+add)); 
        o = min((r+l), o);

        cout << o << endl; 
    }
    return 0; 
}
