#include <bits/stdc++.h> 

using namespace std; 

unsigned int n_participants = 0; 
unsigned int qualification_place = 0; 
unsigned int output = 0; 

vector<int> scores; 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);

    cin >> n_participants >> qualification_place; 
    scores.resize(n_participants+1); 

    for(int i=1; i<=n_participants; i++)
        cin >> scores[i]; 

    for(int i=1; i<=n_participants; i++)
        output += ((scores[i] >= scores[qualification_place])&&(scores[i] > 0));
    
    cout << output << endl; 
    scores.clear(); 
    return 0; 
}
