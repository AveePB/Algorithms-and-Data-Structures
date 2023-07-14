#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+7;
int n, m, a, b, crew[N], size_[N];
vector<int> g[N], gt[N], conn[N];
stack<int> post;
bool vis[N];

void dfs(int v){
    vis[v] = true;
    for(auto w: g[v]){
        if(vis[w])
            continue;
        dfs(w);
    }
    post.push(v);
}

void dfs2(int v, int mark){
    crew[v] = mark;
    size_[mark]++;

    for(auto w: gt[v]){
        if(crew[w] != 0 && crew[w] != mark){
            conn[crew[w]].push_back(mark);
            continue;
        }
        else if(crew[w] != 0){
            continue;
        }
        dfs2(w, mark);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    memset(crew, 0, sizeof(crew));
    memset(size_, 0, sizeof(size_));
    cin >> n >> m;

    while(m--){
        cin >> a >> b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    for(int i=1; i<=n; i++){ 
        if(vis[i])
            continue; 
        dfs(i);
    }

    int mark = 1;
    while(!post.empty()){
        int q = post.top();
        post.pop();

        if(crew[q] != 0)
            continue;

        dfs2(q, mark);
        mark++;
    }

    for(int i=mark-1; i>=1; i--){
        for(auto w: conn[i])
            size_[i] += size_[w];
    }
    
    for(int i=1; i<=n; i++)
        cout << size_[crew[i]] - 1 << '\n';

    return 0;
}
