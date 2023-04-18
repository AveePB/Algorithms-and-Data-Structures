#include <bits/stdc++.h>
 
using namespace std;

vector<int> even_numbers; 
vector<int> odd_numbers; 
int n{};
 
int main() {
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n;

    for(int i=0; i<n; i++){
        int x{}; 
        cin >> x; 

        if(x % 2 == 0)
            even_numbers.push_back(i+1); 
        else 
            odd_numbers.push_back(i+1); 
    }

    if(even_numbers.size() < odd_numbers.size())
        cout << even_numbers[0] << endl; 
    else 
        cout << odd_numbers[0] << endl; 

}
