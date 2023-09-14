class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        string s = to_string(x);
        int i{}, j = s.size()-1;
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
};
