#include <bits/stdc++.h>

using namespace std; 

vector<double> group_sizes(5);  

unsigned int n_groups{}; 

int main()
{
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0); 

    cin >> n_groups; 

    for(int i=0; i<n_groups; i++){
        double n_members{};
        cin >> n_members; 

        group_sizes[n_members]++;  
    }

    double n_taxi{group_sizes[4]}; //4 is max people in taxi 


    //1. we take care of the ones and threes 
    double n_1_3_groups = min(group_sizes[1], group_sizes[3]); 
        //3 + 1 = 4 (1 taxi)
    group_sizes[1] -= n_1_3_groups; 
    group_sizes[3] -= n_1_3_groups; 

    n_taxi += n_1_3_groups; //we append number of the groups (ones and threes) 
    n_taxi += group_sizes[3]; //we append the rest of the threes 

    
    //2. we take care of the twos 
    double n_2s_groups = floor((group_sizes[2] * 2) / 4); // 2*2/4 = 1 (two groups of 2 (2+2 = 4))
        //2 + 2 = 4

    group_sizes[2] -= (n_2s_groups * 2);
    n_taxi += n_2s_groups; 


    //3. we take care of the ones 
    double n_1s_groups = floor((group_sizes[1]) / 4); 
    group_sizes[1] -= n_1s_groups * 4; 
    n_taxi += n_1s_groups; 
    

    //4. we take care of the ones and twos 
    if(group_sizes[1] + group_sizes[2]*2 > 4)
        n_taxi += 2; 
    else if (group_sizes[1] + group_sizes[2]*2 > 0)
        n_taxi++; 

    cout << n_taxi << endl; 

    //cout << "4s: " << group_sizes[4] << endl; 
    //cout << "1+3s: " << n_1_3_groups << endl; 
    //cout << "2+2s: " << n_2s_groups << endl; 
    //cout << "1*4s: " << n_1s_groups << endl; 


    return 0;
}
