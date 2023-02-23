#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
int n{}, ans{}, len[N], tab[N];

//O(N*N)
void setLongestIncreasingSubsequence(){
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++)
            if(tab[i] < tab[j])
                len[i] = max(len[i], 1+len[j]); 
        ans = max(ans, len[i]);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    fill_n(len, N, 1); 
    fill_n(tab, N, 0);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> tab[i];
    setLongestIncreasingSubsequence();
    cout << ans;

    return 0;
}