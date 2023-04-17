#include<bits/stdc++.h>
using namespace std;

vector<int> drink_prices;
vector<int> output; 

unsigned int n_shops;
unsigned int n_days; 

int get_number_of_stores(int money){ //upperbound 
    int left = 0;
    int right = drink_prices.size()-1; 
    
    
    while(left <= right){
        int middle = (left + right) / 2;

        if (drink_prices[middle] == money)
            left = middle + 1;
        
        else if(drink_prices[middle] < money)
            left = middle + 1;
        
        else if (drink_prices[middle] > money) 
            right = middle - 1; 

    }
    return right + 1; //from 0, so we need to add 1  
}

int main()
{
    cin >> n_shops; 
    drink_prices.resize(n_shops);

    for(int i=0; i<n_shops; i++)
        cin >> drink_prices[i]; 
    
    sort(drink_prices.begin(), drink_prices.end()); 
    cin >> n_days; 

    for(int i=0; i<n_days; i++){
        int budget = 0; 
        cin >> budget; 

        output.push_back(get_number_of_stores(budget)); 
    }

    for(int i=0; i<output.size(); i++)
        cout << output[i] << endl;     
    return 0;
}

