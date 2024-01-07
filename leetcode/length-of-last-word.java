class Solution {
    public int lengthOfLastWord(String s) {
        char[] c = s.toCharArray();
        int end = 0;
        for(int i=c.length-1; i>=0; i--) {
            if(c[i] == ' ') continue;
            end = i;
            break;
        }

        int ans = 0;
        for(int i=end; i>=0; i--) {
            if(c[i] == ' ') break;
            ans++;
        }

        return ans;
    }
}
