#include<bits/stdc++.h>
using namespace std;

const int N = 8e6+7;
string pattern{}, text{};
int n{}, m{}, P[N]{};

void set_preffixsuffix(){
    int j{};
    for(int i=1; i<n; i++){
        if(pattern[j] == pattern[i]){
            P[i] = j+1;
            j++;
            continue;
        }

        while (j > 0){
            j = P[j-1];
            if(pattern[j] == pattern[i]){
                P[i] = j+1;
                j++;
                break;
            }
        }
    }
}

void kmp_search(){
    int i{}, j{}; 
    while (i < m && j < n){
        if(text[i] == pattern[j]){
            i++; 
            j++;

            if(j == n){
                cout << i - j + 1<< endl; 
                j = P[j-1]; 
            }
        }
        else{
            if(j != 0)
                j = P[j-1]; 
            else 
                i++;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    cin >> pattern >> text;

    set_preffixsuffix(); 
    kmp_search(); 


    return 0; 
}