#include<bits/stdc++.h>
using namespace std;

struct item{
    long long weight{}, value{};
};

const int N = 1e4+7;
item items[N];

long long knapsack(int n, long long limit){
    long long temp[limit+7] = {0};

    for(auto itm: items){
        temp[itm.weight] = max(temp[itm.weight], itm.value);
        for(long long i=limit; i>=itm.weight; i--)
            temp[i] = max(temp[i], temp[i-itm.weight] + itm.value);
    }

    return temp[limit];
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    long long backpack_size{};
    int n{}; 

    cin >> n >> backpack_size;
    for(int i=0; i<n; i++)
        cin >> items[i].weight >> items[i].value;
    cout << knapsack(n, backpack_size);
    return 0;
}
