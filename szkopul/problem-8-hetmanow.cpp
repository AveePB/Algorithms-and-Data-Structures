#include<iostream>
using namespace std;

const int MAX_N = 16;

bool pos_diag[2*MAX_N], pos_neg[2*MAX_N], pos_col[MAX_N];

int place_queen(int row, int n) {
    if(row == n) return 1;
    int res = 0;

    for(int i=0; i<n; i++) {
        if(pos_diag[i+row]) continue;
        if(pos_neg[i-row+n]) continue;
        if(pos_col[i]) continue;

        pos_diag[i+row] = true;        
        pos_neg[i-row+n] = true;
        pos_col[i] = true;

        res += place_queen(row+1, n);

        pos_diag[i+row] = false;        
        pos_neg[i-row+n] = false;
        pos_col[i] = false;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    fill_n(pos_diag, 2*MAX_N, false);
    fill_n(pos_neg, 2*MAX_N, false);
    fill_n(pos_col, MAX_N, false);

    int n = 0;
    cin >> n;
    
    cout << place_queen(0, n);
    return 0;
}
