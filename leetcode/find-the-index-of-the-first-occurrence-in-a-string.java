
class Solution {
    public int strStr(String haystack, String needle) {
        char[] ha = haystack.toCharArray();
        char[] ne = needle.toCharArray();
        int n = ha.length, m = ne.length;

        for(int i=0; (i+m-1)<n; i++) {
            int res = 0;
            for(int j=0; j<m; j++) {
                if(ha[i+j] == ne[j])
                    res++;
                else
                    break;
            }
            if(res == m)
                return i;
        }
        return -1;
    }
}
