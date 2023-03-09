#include <bits/stdc++.h> 

using namespace std; 

unsigned int n_operations = 0; 
signed int x = 0;

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n_operations; 

    for(int i=0; i<n_operations; i++){
        string statement = ""; 
        cin >> statement; 

        for(char s: statement){
            if (s == '+'){
                x++;
                break; 
            }  
            else if (s == '-'){
                x--;
                break;
            }
        }
    }

    cout << x << endl;

    return 0; 
}
