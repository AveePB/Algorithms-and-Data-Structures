class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(), ans{}, currMax{}, maxLeft[n];
        for(int i=0; i<n; i++){
            currMax = max(currMax, h[i]);
            maxLeft[i] = currMax;
        }

        currMax = 0;
        for(int i=n-1; i>=0; i--){
            currMax = max(currMax, h[i]);
            ans += min(maxLeft[i], currMax) - h[i];
        }
        return ans;
    }
};
