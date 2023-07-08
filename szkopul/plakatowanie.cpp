#include<bits/stdc++.h>
using namespace std;

const int N = 25e4+7;
int n{}, d{}, h{}, ans{};
stack<int> s;

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> d >> h;
    s.push(h);

    for(int i=1; i<n; i++){
        cin >> d >> h;
        while (h < s.top()){
            s.pop();
            ans++;
            if(s.empty())
                s.push(h);
        }
        if(h > s.top())
            s.push(h);
    }

    cout << ans + s.size();
    return 0;
}
