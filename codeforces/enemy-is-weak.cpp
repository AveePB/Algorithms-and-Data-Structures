#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+7;
int n{}, base{}, seg[3*MAXN]{};
pair<int, int> powers[MAXN];
long long ans;

void set_base(int x){
    base = 1;
    while(base < x)
        base *= 2;
}

void update(int i){
    i += base;
    while (i){
        seg[i]++;
        i /= 2;
    }
}

int query(int l, int r, int node=1, int curr_l=0, int curr_r=base-1){
    if(r < curr_l || curr_r < l)
        return 0;
    if(l <= curr_l && curr_r <= r)
        return seg[node];
    int mid = (curr_l+curr_r)/2;
    return query(l, r, 2*node, curr_l, mid) + query(l, r, 2*node+1, mid+1, curr_r);
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n;
    set_base(n);

    for(int i=0; i<n; i++){
        cin >> powers[i].first;
        powers[i].second = i;
    }
    sort(powers, powers+n);
    reverse(powers, powers+n);

    for(int i=0; i<n; i++){
        int right_all = n - i - 1;
        int x = powers[i].second;
        
        int left_less = query(0, x-1);
        int right_less = x - left_less;

        int right_larger = right_all - right_less;
        ans += (long long)left_less * right_larger;
        update(x);
    }

    cout << ans;
    return 0;
}
