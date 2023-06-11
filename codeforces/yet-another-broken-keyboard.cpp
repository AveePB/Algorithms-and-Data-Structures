#include <bits/stdc++.h>
 
using namespace std;

vector<int> subwords_lengths;
vector<int> letters(32);  

string word{}; 
int n{}, k{};
long long n_ways{}; 

long long get_num_ways(long long n){
    return (n * (n + 1)) / 2; 
}

void find_subwords_lens(string w){
    int subword_len{};
    for(auto l: w){
        if(binary_search(letters.begin(), letters.end(), l)){
            subword_len += 1;
        }
        else{
            subwords_lengths.push_back(subword_len); 
            subword_len = 0; 
        }
    } 
    subwords_lengths.push_back(subword_len);
}

int main() {
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);
     
    cin >> n >> k; 
    cin >> word;

    for(int i=0; i<k; i++){
        char l{}; 
        cin >> l;
        letters[i] = int(l); 
    }

    sort(letters.begin(), letters.end()); 
    find_subwords_lens(word);

    for(int len: subwords_lengths){
        n_ways += get_num_ways(len);  
    }

    cout << n_ways << endl; 
    return 0; 
}
