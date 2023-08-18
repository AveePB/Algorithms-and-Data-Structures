#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 1e6 + 7; 

vector<vector<int>> idxs(MAXN);
vector<int> request(MAXN); 

int n{}, m{}, q{}, num{};
int find_min(vector<int>& v, int target);
void test();

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){     
        cin >> num;
        idxs[num].push_back(i);  
    }

    cin >> m;
    while(m--)
        test();

    return 0; 
}

int find_min(vector<int>& v, int min_val){
    int l=0, r=v.size()-1, middle{}, target{};
        while (l <= r){
            middle = (l+r)/2; 
            if(middle < 0 || middle >= v.size()) 
                break;
            
            if(v[middle] <= min_val){
                l = middle+1; 
            }else{
                target = middle; 
                r = middle-1; 
            }
        }
        return v[target];
}

void test(){
    bool result = true;  
    int curr_min{};

    cin >> q;

    for(int i=0; i<q; i++)
        cin >> request[i];

    if(idxs[request[0]].size() > 0)
        curr_min = idxs[request[0]][0]; 
    else 
        result = false; 

    if(result)
        for(int i=1; i<q; i++){
            if(idxs[request[i]].size() > 0 && 
                idxs[request[i]].back() > curr_min){
                    if(idxs[request[i]].size() > 1){
                        curr_min = find_min(idxs[request[i]], curr_min);
                    }
                    else{
                        if(idxs[request[i]][0] > curr_min){
                            curr_min = idxs[request[i]][0]; 
                        }
                        else{
                            result = false; 
                            break;
                        }
                    }
            }
            else{
                result = false; 
                break; 
            }
        }    


    if(result)
        cout << "TAK" << endl;   
    else 
        cout << "NIE" << endl; 
}
