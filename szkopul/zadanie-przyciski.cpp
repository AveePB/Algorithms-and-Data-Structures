#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void btn_game(int n_counters, int n_actions, int* actions, vector<int> counters){
    int global_max = 0;
    int local_max = 0;

    for (int i=0; i<n_actions; i++){
        if (actions[i] == n_counters+1){
            local_max = global_max;
        }
        else{
           if (local_max > counters[actions[i]])
               counters[actions[i]] = local_max + 1;
           else
               counters[actions[i]] += 1;
            global_max = max(global_max, counters[actions[i]]);
        }
    }

    for (int i=0; i<n_counters; i++)
        cout << max(counters[i+1], local_max) << ' ';
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int* actions = new int[0x100000];
    int n_btns, n_actions = 0;
    vector<int> btns;

    cin >> n_btns >> n_actions;
    for (int i=0; i<=n_btns; i++) btns.push_back(0);
    
    for (int i=0; i<n_actions; i++){
        int a = 0;
        cin >> a;
        actions[i] = a;
    }

    btn_game(n_btns, n_actions, actions, btns);
    return 0;
}
