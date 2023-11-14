class Solution {
public:
    string findSubString(string s, int l, int r){
        while (true){
            if(l == -1 || r == s.size())
                break;
            if(s[l] != s[r])
                break;
            l--, r++;
        }
    
        if(l>r) return "";
        
        return s.substr(l+1, ((r-1)-(l+1)+1));
    }

    string longestPalindrome(string s) {
        string ans{};

        for(int i=0; i<s.size(); i++){
            string even = findSubString(s, i-1, i);
            string odd = findSubString(s, i-1, i+1);
            if(ans.size() < even.size())
                ans = even;
            if(ans.size() < odd.size())
                ans = odd;
        }
        return ans;
    }
};
