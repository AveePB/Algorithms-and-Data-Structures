#include <iostream>
#include <vector>

using namespace std; 

int bestSum(vector<int> vec) {
    if (vec.size() == 0) return 0;
    int ans = vec[0], sum = vec[0]; 

    for (int i = 1; i<vec.size(); i++) {
        if (sum < 0) 
            sum = vec[i];
        else 
            sum += vec[i];

        if (ans < sum) ans = sum;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v;
    int x = 0;

    while (true) {
        cin >> x;
        if (x == 0) break;
        v.push_back(x);
    }
    cout << bestSum(v);
    return 0;
}
