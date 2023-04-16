#include <bits/stdc++.h>
using namespace std;
     
const int MAXN = 5e2+7;
vector<vector<int>> b(MAXN, vector<int> (MAXN));
vector<int> seg(4*MAXN);  
int n{}, m{}, q{}, base{}; 
     
int get_score(int idx){
    int max_score{}, curr_score{}; 
    for(int i=0; i<m; i++){
    		if(b[idx][i] == 0){
    			max_score = max(max_score, curr_score); 
    			curr_score = 0; 
    		}
    		else{
    			curr_score++; 
    		}
    }	
    return max(max_score, curr_score); 
} 
     
void set_base(int& num){
    base = 1; 
    while(base < num)
    		base *= 2;
}
     
void build(int& max_row, int& max_cln){
    for(int i=0; i<max_row; i++)
    		seg[base+i] = get_score(i);
     
    for(int i=base-1; i>0; i--)
    		seg[i] = max(seg[2*i], seg[2*i+1]);
}
     
     
void update_set(int idx, int val){
    int node = base + idx; 
    seg[node] = val; 
    node /= 2;
     
    while(node){
    		seg[node] = max(seg[2*node], seg[2*node+1]);  
    		node /= 2; 
    }
}
     
     
int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); 
    cin >> n >> m >> q; 
    	 
    for(int i=0; i<n; i++)
    		for(int j=0; j<m; j++)
    			  cin >> b[i][j];
    	
    set_base(n);
    build(n, m);
    	
    while (q--){
    		int i{}, j{}; 
    		cin >> i >> j;
    		i--, j--; 
     
    		if(b[i][j] == 0)
    			b[i][j] = 1; 
    		else
    			b[i][j] += -1; 
     
    		int curr_score = get_score(i); 
    		update_set(i, curr_score); 
     
    		cout << seg[1] << '\n'; 
    }	
    return 0;
}
