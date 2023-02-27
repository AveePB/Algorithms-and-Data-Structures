#include<bits/stdc++.h>
using namespace std;

const int N = 3e3+7;
vector<vector<int>> v(N);
vector<int> topo_sort;
queue<int> q;
int n{}, m{}, d[N];

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    memset(d, 0, sizeof(d));
    
    cin >> n >> m;
    //n -> <1, n>
    for(int i=0; i<m; i++){
        int a{}, b{};
        cin >> a >> b;

        v[a].push_back(b);
        d[b]++;
    }
    
    for(int i=1; i<=n; i++)
        if(d[i] == 0)
            q.push(i);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int a: v[node]){
            d[a]--;
            if(d[a] == 0)
                q.push(a);
        }
        topo_sort.push_back(node);
    }

    for(int i=0; i<topo_sort.size(); i++)
        cout << topo_sort[i] << ' ';


    return 0;
}
