#include<bits/stdc++.h>
using namespace std;

struct anagram{
    string str{};
    long long hash{};
};

const int N = 3e3+7;
vector<pair<string, int>> v;
map<int, set<string>> m;
anagram a[N];
int n{};

bool comp(pair<string, int> p1, pair<string, int> p2){
    return p1.first < p2.first;
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i].str;
        for(auto c: a[i].str){
            long long c_hash = int(c);
            c_hash *= int(c);
            c_hash *= int(c);
            c_hash *= int(c);
            a[i].hash += c_hash;
        }
        m[a[i].hash].insert(a[i].str);
    }

    for(auto p: m){
        string k = *p.second.begin();
        int hash = p.first;
        v.push_back({k, hash});
    }

    sort(v.begin(), v.end());

    for(auto elm: v){
        for(auto p: m[elm.second])
            cout << p << ' ';
        cout << '\n';
    }

    return 0;
}
