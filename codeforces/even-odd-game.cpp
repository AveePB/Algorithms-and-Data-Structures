#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
void anmol()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
 
 

void solve(){
 
int n;
cin>>n;
int a[n];
 
for(int i =0; i<n; i++){
  cin>>a[i];
  
}
 
sort(a,a+n);
reverse(a,a+n);

int sum1 =0;
int sum2 =0;
int count =0;
for(int i =0; i<n; i++){
    
    if(count%2==0){
    if(a[i]%2==0){
      sum1+=a[i];
      
    }
    }
    else {
      if(a[i]%2==1){
      sum2+=a[i];
 
      }
    }
 
    count++;
 
}
 
        if(sum1>sum2){
            cout<<"Alice"<<endl;
        }
        else if(sum1==sum2){
           cout<<"Tie"<<endl; 
        }
        else  cout<<"Bob"<<endl;

}
 
int32_t main(){
 
 
  anmol();
  int t;
  cin>>t;

  while(t--){
    solve();
  }
 
}
