#include <bits/stdc++.h> 
using namespace std;

const int N = 1e6+7;
int n{}, q{}, base{}, seg[N]{};

void set_base(int &num){
    base = 1;
    while (base < num)
        base *= 2;
}

void build_tree(){
    for(int i=base-1; i>0; i--)
        seg[i] = max(seg[2*i], seg[2*i+1]);
}

int query_max(int l, int r, int curr_l, int curr_r, int node){
    if(l > curr_r || curr_l > r)
        return 0; 
    
    if(l <= curr_l && curr_r <= r)
        return seg[node]; 
    
    int mid = (curr_l+curr_r)/2;
    int q1 = query_max(l, r, curr_l, mid, 2*node); 
    int q2 = query_max(l, r, mid+1, curr_r, 2*node+1); 
    
    return max(q1, q2);
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
    cin >> n >> q; 
    set_base(n);

    for(int i=0; i<n; i++) 
        cin >> seg[base+i]; 
    build_tree(); 

    for(int i=0; i<q; i++){
        int l{}, r{};
        //0 <= l, r < n 
        cin >> l >> r;

        cout << query_max(l, r, 0, base-1, 1) << '\n';  
    }
    //0..n-1

    return 0; 
}
