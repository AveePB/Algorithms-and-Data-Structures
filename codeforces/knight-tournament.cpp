#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+7;
int n{}, m{}, l{}, r{}, x{};

vector<int> output(MAXN); 
set<int>::iterator it;
set<int> s;

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    
    cin >> n >> m; 
    
    for(int i=1; i<=n+1; i++)
        s.insert(i);

    while(m--){ 
        cin >> l >> r >> x; 
        it = s.lower_bound(l); 
        while (*it<=r){
            if(*it != x){
                output[*it] = x; 
                s.erase(it++); 
            }
            else 
                it++; 
        }
    }

    for(int i=1; i<=n; i++)
        cout << output[i] << ' '; 
    
    return 0; 
}
