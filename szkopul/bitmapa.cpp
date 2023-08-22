#include <bits/stdc++.h>
using namespace std;

struct cell{
    int row{}, cln{}, steps{}; 
}; 

const int MAXN = 182 + 7;
 
vector<vector<bool>> vis(MAXN, vector<bool>(MAXN));
vector<vector<int>> ans(MAXN, vector<int>(MAXN));
queue<cell> q; 

int n{}, m{}; 
string r{};

bool is_valid(int row, int cln); 
void bfs();

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n >> m; 

    for(int i=0; i<n; i++){
        cin >> r; 
        for(int j=0; j<m; j++){
            if(r[j] == '1'){
                cell c;
                c.row = i, c.cln = j, c.steps = 0; 
                q.push(c);
                vis[i][j] = 1; 
            }
        }         
    }

    bfs();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << ans[i][j] << ' '; 
        }
        cout << '\n'; 
    }

    return 0; 
}

bool is_valid(int row, int cln){
    return (row >= 0 && row < n) && (cln >= 0 && cln < m); 
}

void bfs(){
    vector<pair<int, int>> cell_mod = 
        {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
    
    while (!q.empty()){
        cell curr_c = q.front(); 
        q.pop(); 
        
        ans[curr_c.row][curr_c.cln] = curr_c.steps; 
        for(int i=0; i<4; i++){
            int row = curr_c.row + cell_mod[i].first; 
            int cln = curr_c.cln + cell_mod[i].second; 

            if(is_valid(row, cln) && !(vis[row][cln])){
                vis[row][cln] = 1; 
                cell c; 
                c.cln = cln, c.row = row, 
                c.steps = curr_c.steps+1; 
                q.push(c); 
            }
        }
    }

}
