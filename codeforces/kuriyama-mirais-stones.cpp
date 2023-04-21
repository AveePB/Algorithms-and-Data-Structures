#include <bits/stdc++.h>
 
using namespace std; 
 
void question(int l_idx, int r_idx, vector<long long int>& sum); 
 
vector<long long int> sum_of_stones(1); 
vector<long long int> sum_of_sorted_stones(1); 
 
int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 
 
 
    //STONES SECTION
    int n_stones{}; 
    cin >> n_stones; 
    vector<long long int> stones;
    
    for(int i=0; i<n_stones; i++){
        long long int stone{}; 
        cin >> stone; 
        stones.push_back(stone); 
    }
 
    //Sum of the stones 
    for(int i=1; i<=n_stones; i++){
        sum_of_stones.push_back(sum_of_stones[i-1] + stones[i-1]); 
    }
 
    //Sum of the sorted stones 
    sort(stones.begin(), stones.end()); 
    for(int i=1; i<=n_stones; i++){
        sum_of_sorted_stones.push_back(sum_of_sorted_stones[i-1] + stones[i-1]); 
    }
 
 
    //QUESTIONS SECTION 
    int n_questions{}; 
    cin >> n_questions; 
 
    for(int i=0; i<n_questions; i++){
        int type{}, l_idx{}, r_idx{};
        cin >> type >> l_idx >> r_idx; 
 
        if (type == 1)
            question(l_idx, r_idx, sum_of_stones); 
        else 
            question(l_idx, r_idx, sum_of_sorted_stones); 
    }
 
    return 0; 
}
 
void question(int l_idx, int r_idx, vector<long long int>& sum){
    cout << sum[r_idx] - sum[l_idx-1] << endl; 
}
 
