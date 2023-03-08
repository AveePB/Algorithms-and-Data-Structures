#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7; 

vector<int> v(MAXN); 
int n{}, k{}, num{}; 

void query();

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++)
        cin >> v[i]; 
    
    for(int i=0; i<k; i++)
        query();

    return 0; 
}

void query(){
    cin >> num;
    int l=0; int r=n; 
    while (r-l > 1){
        int middle = (l+r)/2; 
        if(v[middle] > num)
            r = middle;
        else 
            l = middle;
    }

    if(v[l] == num)
        cout << "YES" << endl; 
    else 
        cout << "NO" << endl;
}
