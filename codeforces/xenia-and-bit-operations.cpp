#include<bits/stdc++.h>

using namespace std;

const int B = 131072 + 7; 

vector<long long> tree(2*B); 
int n{}, m{}, base{};
long long p{}, b{};

void init_build(int curr_base, int curr_n, bool is_or){
    if(curr_n == 0)
        return; 

    if(is_or)
        for(int i=0; i<curr_n; i++)
            tree[curr_base+i] = tree[2*(curr_base+i)] | tree[2*(curr_base+i)+1];
    else
        for(int i=0; i<curr_n; i++)
            tree[curr_base+i] = tree[2*(curr_base+i)] ^ tree[2*(curr_base+i)+1];

    init_build(curr_base/2, curr_n/2, !is_or); 
}

void update_set(int idx, int val, bool is_or){
    int node = (base + idx); //We compute the node 
    tree[node] = val; 
    node /= 2; 

    while(node){
        if(is_or)
            tree[node] = tree[2*node] | tree[2*node+1]; 
        else 
            tree[node] = tree[2*node] ^ tree[2*node+1];

        //We compute next node and change bit operation 
        is_or = !is_or; 
        node /= 2; 
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);
    
    //INPUT 1
    cin >> n >> m;
    base = (int) pow(2, n);
    
    //INPUT 2
    for(int i=0; i<base; i++)
        cin >> tree[base+i];
    
    //BUILDING THE TREE BASE == N
    init_build(base/2, base/2, true); 

    //INPUT 3 
    for(int i=0; i<m; i++){
        cin >> p >> b;

        update_set(p-1, b, true); 
        cout << tree[1] << '\n'; 
    }
    
    return 0; 
}
