class Solution {
public:
    vector<vector<int>>ans;
    int n, k;
    void backtracking(vector<int>&v, int t, int pos){
        if(pos == k){
            ans.push_back(v);
            return;
        }
        for(int i=t; i<=n; i++){
            v[pos] = i;
            backtracking(v, i+1, pos+1);
        } 
    }

    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> g(k);
        backtracking(g, 1, 0);
        return ans;
    }
};
