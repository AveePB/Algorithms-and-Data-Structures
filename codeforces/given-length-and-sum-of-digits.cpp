#include <bits/stdc++.h>
 
using namespace std;

int m{}, s{}; 

string find_max(int n_digits, int sum);
string find_min(string max_n);

int main() {
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    string s1{}, s2{}; 

    cin >> m >> s;  

    s2 = find_max(m, s);
    s1 = find_min(s2); 

    cout << s1 << " " << s2 << endl; 
}


string find_max(int n_digits, int sum){
    string n{}; 

    if(n_digits > 1 && sum == 0)
        return "-1"; 
    
    while(sum >= 9){
        sum -= 9; 
        n += '9'; 
    }

    if (sum != 0)
        n += to_string(sum);     
    
    int current_len = n.length();
    for(int i=0; i<n_digits - current_len; i++)
        n += '0';   

    
    if(n.length() == n_digits){
        return n;
    }
    
    return "-1";    
}  

string find_min(string max_n){
    if(int(max_n.length()) == 1 || max_n == "-1")
        return max_n; 
    
    //cHECK IF ALL NS ARE SAME !! DO IT 
    bool is_same = true; 
    for(char l: max_n){
        is_same = (l == max_n[0]); 
    }

    if (is_same)
        return max_n; 

    
    for(int i=int(max_n.length())-1; i>=0; i--){
        if(max_n[i] != '0'){
            max_n[i] -= 1; 
            break;
        }
    }
    reverse(max_n.begin(), max_n.end()); 
    max_n[0] += 1;  

    return max_n;
}
