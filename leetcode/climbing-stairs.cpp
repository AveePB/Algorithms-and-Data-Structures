class Solution {
public:
    int climbStairs(int n) {
        int a1=1, a2=1;
        for(int i=1; i<n; i++){
            int newa2 = a1 + a2;
            a1 = a2;
            a2 = newa2;
        }

        return a2;
    }
};
