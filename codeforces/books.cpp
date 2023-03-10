 
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=2e5+5;
int prefix[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n,t;
    cin>>n>>t;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>prefix[i];
        prefix[i]+=prefix[i-1];
    }
    for(int i=0;i<=n;i++){
    int l=1+i,r=n;
    while(l<=r){
        int m=(l+r)/2;
        if(prefix[m]-prefix[i]<=t)
         l=m+1;
         else r=m-1;
    }
      ans=max(ans,l-1-i);
    }
    cout<<ans;
    return 0;
}
 	 	
