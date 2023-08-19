#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 2e3 + 7;

vector<vector<int>> v(MAXN, vector<int>(MAXN));
vector<int> histo(MAXN); 
int n{}, max_area{};

int read_histogram(); 

int main(){
    ios_base::sync_with_stdio(0); 
    cout.tie(0); 
    cin.tie(0);
    
    cin >> n;  

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
            v[i][j] ^= 1;
        }
    }
 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] == 0)
                histo[j] = 0; 
            else 
                histo[j] += v[i][j];                 
        }
        max_area = max(max_area, read_histogram());
    }
    cout << max_area << endl; 
    

    return 0; 
}

int read_histogram(){
    stack<int> st; 
    int area{}, i{};
    
    while (i<n){
        while (!st.empty() && histo[st.top()] > histo[i]){
            int top = st.top();
            int height = histo[top]; 
            st.pop(); 

            if(st.empty()){
                area = max(area, height*i); 
            }
            else{
                int len = i - st.top() - 1;
                area = max(area, height * len);  
            }
        }
        st.push(i);
        i++;
    }
    
    return area; 
}
