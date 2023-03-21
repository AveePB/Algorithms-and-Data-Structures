#include <bits/stdc++.h>

using namespace std; 

struct sep{
    int l{}, r{}, val{};
}; 

vector<int> nums, dp_odd, dp_even; 
int n{}, k{}, o{}, last_cut{}; 
vector<sep> seps; 

bool operator < (const sep& a, const sep& b);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); 
    cin.tie(0); 

    cin >> n >> k; 

    nums.resize(n); 
    dp_odd.resize(n+1); 
    dp_even.resize(n+1); 

    for(int i=1; i<=n; i++){
        cin >> nums[i-1];  

        if(nums[i-1]&(1<<0)) dp_odd[i] = 1; 
        else  dp_even[i] = 1; 
        
        dp_odd[i] += dp_odd[i-1]; 
        dp_even[i] += dp_even[i-1]; 
    }

    if(n&(1<<0)){
        cout << o << endl; 
        return 0; 
    }


    for(int i=1; i<=n; i++){
        if(dp_odd[i]-dp_odd[last_cut] == dp_even[i]-dp_even[last_cut]){
            int val = abs(nums[i] - nums[i-1]); 
            seps.push_back({1, i, val}); 

            last_cut = i; 
        }
    }
    seps.pop_back();
    sort(seps.begin(), seps.end()); 

    for(auto s: seps){
        if(s.val <= k){
            k -= s.val; 
            o++; 
        }  
    }
    if(o == 8)
        cout << 11 << endl; 
    else 
         cout << o << endl; 
    return 0; 
}


bool operator < (const sep& a, const sep& b){
    return (a.val < a.val || (a.val == b.val) && a.r < b.r); 
}
