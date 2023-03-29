#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , number;
    cin >> n >> number;

    if(number <= (n+1)/2){
        cout << (2*number)-1 << endl;
    }else{
        number = number - ((n+1) /2);
        cout << 2*number << endl;
    }

    return 0;
}
