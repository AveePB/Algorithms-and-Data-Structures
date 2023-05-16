#include <bits/stdc++.h>

using namespace std; 

const long long correct_s = 84*84+105*105+109*109+117*117+114*114; 
map<string, string> results; 

int n_tests{}, n{}; 
string s{}; 

void test(); 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 
    
    cin >> n_tests; 
    while (n_tests--){
        cin >> n >> s; 

        if(n != 5){
            cout << "NO" << endl; 
            continue; 
        }
        
        if(results.find(s) != results.end()){
            cout << results[s] << endl; 
            continue; 
        }

        test(); 
    }

    return 0; 
}

void test(){
    long long sum{}; 
    for(char c: s)
        sum += int(c) * int(c); 

    if(sum == correct_s)
        results[s] = "YES";
    else 
        results[s] = "NO"; 

    cout << results[s] << endl;  
}
