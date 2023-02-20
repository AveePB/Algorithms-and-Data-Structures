#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
int n{}, m{};
long long kadane(vector<int>& v, int& global_start, int& global_finish){
    int global_max=INT_MIN, local_max{};
    int local_start, local_finish;

    for(int i=0; i<v.size(); i++){
        if(local_max+v[i] > v[i]){
            local_max += v[i];
            local_finish = i;
        }
        else{
            local_start = i;
            local_finish = i; 
            local_max = v[i];
        }

        if(local_max > global_max){
            global_max = local_max;
            global_start = local_start;
            global_finish = local_finish;
        }
    }
    return global_max;
}

long long kadane2D(vector<vector<int>>& v){
    int maxRecLeft=-1,maxRecRight=-1,
    maxRecTop=-1, maxRecBottom=-1;
    long long maxRecSum{};

    for(int left=0; left<m; left++){
        vector<int> row_sum(n);
        for(int right=left; right<m; right++){
            for(int i=0; i<n; i++)
                row_sum[i] += v[i][right];

            int start{}, finish{};
            long long recSum = kadane(row_sum, start, finish);
            
            if(recSum > maxRecSum){
                maxRecSum = recSum;
                maxRecLeft = left;
                maxRecRight = right;
                maxRecTop = start;
                maxRecBottom = finish;
            }
        }
    }
    
    cout << "LEFT UP CORNER (ROW, CLN): ";
    cout << '(' << maxRecTop << ',' << maxRecLeft << ')' << '\n';

    cout << "RIGHT DOWN CORNER (ROW, CLN): ";
    cout << '(' << maxRecBottom << ',' << maxRecRight << ')' << '\n';

    cout << "SUM: ";
    cout << maxRecSum << '\n';

    return maxRecSum;
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    vector<vector<int>> v(N, vector<int>(N));
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> v[i][j];

    long long sum = kadane2D(v);
	return 0;
}
