#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    pair<long long, long long> most_often;
    map<long long, long long> nums;

    for (int i=0; i<1000000; i++) {
        long long n = 0;
        cin >> n;

        if (n == 0)
            break;
        else
            nums[n] += 1;

        if (nums[n] > most_often.second) {
            most_often.first = n;
            most_often.second = nums[n];
        }
        else if (nums[n] == most_often.second) {
            if (n > most_often.first) {
                most_often.first = n;
                most_often.second = nums[n];
            }
        }
    }
    cout << most_often.first;
    return 0;
}
