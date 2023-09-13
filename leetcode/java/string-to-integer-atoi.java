class Solution {
    public int myAtoi(String s) {
        char[] str = s.toCharArray();
        int idx=0;
        while(idx < str.length && str[idx] == ' ') idx++;
        if(str.length == idx)
            return 0;

        boolean neg = (str[idx] == '-');
        if(neg || str[idx] == '+') idx++;


        int res = 0;
        while((idx < str.length) && ('0' <= str[idx] && str[idx] <= '9')) {
            if(214748364 < res) {
                if(neg)
                    return Integer.MIN_VALUE;
                return Integer.MAX_VALUE;
            }
            else if(214748364 == res ) {
                if(neg && (str[idx] - '0' >= 8))
                    return Integer.MIN_VALUE;
                else if(!neg && (str[idx] - '0' >= 7))
                    return Integer.MAX_VALUE;
            }
            res *= 10;
            res += str[idx] - '0';
            idx++;
        }

        if(neg)
            res *= -1;
        return res;
    }
}
