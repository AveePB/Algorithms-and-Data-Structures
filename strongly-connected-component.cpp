#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
int n{}, m{}, a{}, b{}, ans[N]{};
vector<int> g[N], gt[N];
stack<int> post;
bool vis[N]{};

void dfs(int v){
    vis[v] = true;
    for(auto w: g[v]){
        if(vis[w])
            continue;
        dfs(w);
    }
    post.push(v);
}

void dfs2(int v, int curr_mark){
    ans[v] = curr_mark;
    for(auto w: gt[v]){
        if(ans[w] != 0)
            continue;    
        dfs2(w, curr_mark);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
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

        if(ans[q] != 0)
            continue;    
        dfs2(q, mark);
        mark++;
    }
    
    for(int i=1; i<=n; i++) cout << i << '.' << ans[i] << '\n';

    return 0;
}
