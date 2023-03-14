#include<bits/stdc++.h>

using namespace std;

int n{}, m{}, a{}, b{};

//n <- planned rides 
//m <- rides covered by m ride ticket 
//a <- regular ticket  
//b <- m ride ticket

int main()
{
    cin >> n >> m >> a >> b;

    int cost1 = (n/m)*b + min((n%m)*a, b); 
    int cost2 = n*a; 

    cout << min(cost1, cost2) << endl; 

    return 0;
}
