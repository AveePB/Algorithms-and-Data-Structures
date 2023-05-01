class Solution {
public:
    vector<vector<int>> mat;
    int max_row, max_cln;
    int inf = 120000000;

    void bfs(int row, int cln, int prev_row, int prev_cln, int dist){
        if(row == max_row || row == -1)
            return;
        if(cln == max_cln || cln == -1)
            return;
        if(dist >= mat[row][cln])
            return;
        
        mat[row][cln] = dist;

        if(row+1 != prev_row)
            bfs(row+1, cln, row, cln, dist+1);
        if(row-1 != prev_row)
            bfs(row-1, cln, row, cln, dist+1); 
        if(cln+1 != prev_cln)
            bfs(row, cln+1, row, cln, dist+1);
        if(cln-1 != prev_cln) 
            bfs(row, cln-1, row, cln, dist+1);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        mat = v;

        stack<pair<int, int>> s;
        max_row = mat.size();
        max_cln = mat[0].size();

        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat[0].size(); j++)
                if(mat[i][j] == 0)
                    s.push({i, j});
                else
                    mat[i][j] = inf;
        
        while (!s.empty()){
            pair<int, int> pos = s.top();
            s.pop();
            bfs(pos.first+1, pos.second, pos.first, pos.second, 1);
            bfs(pos.first-1, pos.second, pos.first, pos.second, 1);
            bfs(pos.first, pos.second+1, pos.first, pos.second, 1);
            bfs(pos.first, pos.second-1, pos.first, pos.second, 1);
        }

        return mat;
    }
};