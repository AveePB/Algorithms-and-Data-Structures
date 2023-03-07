#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 100; 

int n_boys{}, n_girls{}, n_global_pairs{}; 

vector<int> boys(MAXN+7); 
vector<int> girls(MAXN+7); 

int main() {
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n_boys; 

    for(int i=0; i<n_boys; i++){
        int boys_skill{}; 
        cin >> boys_skill; 
        boys[boys_skill] += 1; 
    }

    cin >> n_girls; 

    for(int i=0; i<n_girls; i++){
        int girls_skill{}; 
        cin >> girls_skill; 
        girls[girls_skill] += 1; 
    }

    for(int i=1; i<=MAXN; i++){

        for(int j=i-1; j<=i+1; j++){
            int n_curr_pairs = min(boys[i], girls[j]);
            n_global_pairs += n_curr_pairs; 
            girls[j] -= n_curr_pairs;
            boys[i] -= n_curr_pairs; 

        }
    }

    cout << n_global_pairs << endl;     
}
