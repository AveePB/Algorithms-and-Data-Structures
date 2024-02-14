class Solution {
    public String minWindow(String s, String t) {
        int[] c_str = new int[58], c_tar = new int[58];
        char[] str = s.toCharArray(), tar = t.toCharArray();
        int l=0, l_ptr=0, r_ptr=1000000, need=0, have=0;

        for (char c : tar) if(++c_tar[c-65] == 1) need++;
        for(int r=1; r<=str.length; r++) {
            int r_char = str[r-1] - 65;
            if(++c_str[r_char] == c_tar[r_char]) have++;
            while (have == need) {
                if(r_ptr-l_ptr > r-l) {
                    r_ptr = r;
                    l_ptr = l;
                }
                int l_char = str[l] - 65;
                if(--c_str[l_char] < c_tar[l_char]) have--;
                l++;
            }
        }
        if(r_ptr == 1000000) return "";
        return s.substring(l_ptr, r_ptr);
    }
}
