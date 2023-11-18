public class Solution {
    public int getSubstringLen(char[] str, int idx) {
        for(int i=idx; i<str.length; i++)
            if(str[idx] != str[i])
                return i - idx;
        return str.length - idx;
    }

    public String countAndSay(int n) {
        char[] str = new char[]{'1'};
        int idx = 1;
        while(idx < n) {
            StringBuilder sb = new StringBuilder();
            int i = 0;
            while (i < str.length) {
                int len = getSubstringLen(str, i);
                sb.append(len);
                sb.append(str[i]);
                i += len;
            }
            str = sb.toString().toCharArray();
            idx++;
        }
        return String.valueOf(str);
    }
}
