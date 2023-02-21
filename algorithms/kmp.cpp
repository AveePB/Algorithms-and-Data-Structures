#include <iostream>
using namespace std;

const int N = 1e3+7; 

string pattern{}, text{}; 
int P[N]{}; 

void set_pattern(string& s){
    int j{}; 
    for(int i=1; i<int(s.length()); i++){
        if(s[j] == s[i]){
            P[i] = j+1;
            j++;  
            continue; 
        }

        while(j > 0){
            j = P[j-1]; 
            if(s[j] == s[i]){
                P[i] = j+1; 
                j++; 
                break; 
            }
        }
    }
}

bool has_substring(string& t, string& p){
    int i{}, j{}; 
    while (i < t.length() && j < p.length()){
        if(t[i] == p[j]){
            i++; 
            j++; 
        }
        else{
            if(j != 0)
                j = P[j-1]; 
            else 
                i++;
        }
    }

    if(j == p.length())
        return true; 
    
    return false; 
}


int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> pattern >> text;
    set_pattern(pattern); 

    cout << has_substring(text, pattern) << '\n';

    return 0;
}
