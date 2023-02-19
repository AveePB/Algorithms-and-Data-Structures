#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n{};

int kadane(vector<int> &a){
    int local_max{}, global_max{INT_MIN};
    for(int i=0; i<a.size(); i++){
        local_max = max(local_max+a[i], a[i]);
        if(local_max > global_max)
            global_max = local_max;
    }
    return global_max;
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> n;
    v.resize(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    cout << kadane(v);

    return 0;
}
