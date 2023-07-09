#include<bits/stdc++.h>
using namespace std;

struct interval{
    int start, end;
    long long time{};
};

const int N = 1e4+7;
long long ans{};
interval p[N];
int n{};

bool compP(interval p1, interval p2){
    return p1.end <= p2.end; 
}

long long binary_search(int l, int r, int tar){
    while(r-l>1){
        int mid = (l+r)/2;
        if(p[mid].end > tar)
            r = mid;
        else 
            l = mid;
    }
    if(p[l].end <= tar)
        return p[l].time;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> p[i].start >> p[i].end;
    
    sort(p, p+n, compP);
    p[0].time = p[0].end - p[0].start;

    for(int i=1; i<n; i++){
        p[i].time = (p[i].end - p[i].start) ;
        p[i].time += binary_search(0, i+1, p[i].start);

        p[i].time = max(p[i].time, p[i-1].time);
    }

    cout << p[n-1].time;

    return 0;
}
