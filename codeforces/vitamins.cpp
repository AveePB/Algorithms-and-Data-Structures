#include<bits/stdc++.h>
using namespace std;

vector<int> v(8, 1e6);
int n{}, a{}, b{}, c{}; 
string vitamins{};

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
     
    cin >> n;
    v[0] = 0; 
    
    while(n--){
        int total_mask{}, price{};
        cin >> price >> vitamins;

        for(int i=0; i<int(vitamins.length()); i++){    
            int p = vitamins[i] - 65;
            int curr_mask = pow(2, p);
            
            if(p == 0) a++;  
            else if (p == 1) b++; 
            else c++;  

            total_mask += curr_mask; 
        }

        if(int(vitamins.length()) > 1){
            for(int i=0; i<int(vitamins.length()); i++){
                int p = vitamins[i] - 65;
                int curr_mask = total_mask - pow(2, p);

                for(int j=7; j>=curr_mask; j--)
                    v[j] = min(v[j], v[j-curr_mask] + price);
            }
        }


        for(int i=7; i>=total_mask; i--)
            v[i] = min(v[i], v[i-total_mask] + price);
    }

    if(a > 0 && b > 0 && c > 0)
        cout << v[7]; 
    else 
        cout << -1;

    return 0; 
}
