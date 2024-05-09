#include <bits/stdc++.h>

using namespace std; 

struct pt{
    int num{};
    long long weight{}; 
}; 
 
const int MAXN = 1e4+7;

vector<long long> dist(MAXN, INT_MAX); 
vector<vector<pt>> graph(MAXN); 
vector<bool> vis(MAXN); 

int t{}, v{}, k{}; 

void dijkstra(int start);
void test();

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);
    
    cin >> t;
    while (t--)
        test(); 
    return 0; 
}

void dijkstra(int start){
    dist[start] = 0; 
    priority_queue<int> q;
    q.push(start); 

    while(!q.empty()){
        int curr = q.top(); 
        vis[curr] = true; 
        q.pop();

        for(pt p: graph[curr]){
            if(p.weight + dist[curr] < dist[p.num]){
                dist[p.num] = p.weight + dist[curr]; 
                q.push(p.num); 
            }
        }
    } 

}

void test(){
    cin >> v >> k;

    for(int i=0; i<=v; i++){
        graph[i].clear(); 
        dist[i] = INT_MAX; 
        vis[i] = false; 
    }

    for(int i=0; i<k; i++){
        int a{}; pt p; 
        cin >> a >> p.num >> p.weight;
        graph[a].push_back(p);
    }

    int start_pt{}, end_pt{}; 
    cin >> start_pt >> end_pt;
    dijkstra(start_pt);

    if(vis[end_pt])
        cout << dist[end_pt] << endl; 
    else 
        cout << "NO" << endl; 

}
