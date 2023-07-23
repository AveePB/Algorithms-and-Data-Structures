#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n_guests=0, ans=0; 
    vector<int> guest_nums;

    guest_nums.push_back(0);
    cin >> n_guests;

    for (int i=0; i<n_guests; i++) {
        int guest_num = 0;
        cin >> guest_num;
        guest_nums.push_back(guest_num);
    }

    for (int i=1; i<=n_guests; i++) {
        int pot_idx=i;

        if (guest_nums[pot_idx] != 0) {
            while (true) {
                if (guest_nums[pot_idx] == i) {
                    guest_nums[pot_idx] = 0;
                    ans++;
                    break;
                }
            int new_idx = guest_nums[pot_idx];
            guest_nums[pot_idx] = 0;
            pot_idx = new_idx;
            }
        }
    }
    cout << ans;
    return 0;
}
