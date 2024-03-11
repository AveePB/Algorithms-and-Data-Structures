class Solution {
public:
    int numDecodings(string s) {
        long long dp[101];
        fill_n(dp, 101, 0);
        dp[0] = 1; dp[1] = 1;
        
        if(s[0] == '0')
            return 0;
        
        for(int i=2; i<=s.size(); i++){
            int one_digit = stoi(s.substr(i-1, 1));
            int two_digits = stoi(s.substr(i-2, 2));
            
            if(one_digit > 0)
                dp[i] = dp[i-1];

            if(two_digits >= 10 && two_digits <= 26)
                dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};
