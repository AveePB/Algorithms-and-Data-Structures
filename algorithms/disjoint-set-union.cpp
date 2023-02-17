#include<bits/stdc++.h>
using namespace std;

const int NQ = 5e5+7;
int rep[NQ], size_[NQ];
int n{}, q{};

int findUnion(int v){
    if(rep[v] == v)
        return rep[v];
    rep[v] = findUnion(rep[v]);
    return rep[v];
}

void mergeUnion(int a, int b){
    int union_a = findUnion(a);
    int union_b = findUnion(b);
    if(union_a == union_b)
        return;

    if(size_[union_a] >= size_[union_b]){
        size_[union_a] += size_[union_b];
        rep[union_b] = union_a;
    }
    else{
        size_[union_b] += size_[union_a];
        rep[union_a] = union_b;
    }
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> q;
    //n -> <1, n>

    for(int i=1; i<=n; i++){
        size_[i] = 1;
        rep[i] = i;
    }
    
    while (q--){
        int t{}, a{}, b{};
        cin >> t >> a >> b;

        if(t == 1){
            mergeUnion(a, b);
        }
        else{
            if(findUnion(a) == findUnion(b))
                cout << "Numbers are in the same union\n"; 
            else
                cout << "Numbers aren't in the same union\n";
        }
    }
    
    return 0;
}
