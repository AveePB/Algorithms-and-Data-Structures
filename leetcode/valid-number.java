class Solution {
    public boolean isNumber(String s) {
        int sign_ptr=0, digit_count=0, dot_count=0, e_count=0;
        int digit = -1, dot = -1, e = -1;
        int[] signs = new int[2];

        for(int i=s.length()-1; i>=0; i--) {
            if(s.charAt(i) == '-' || s.charAt(i) == '+') {
                if(sign_ptr == 2) return false;
                signs[sign_ptr] = i;
                sign_ptr++;
            }
            else if('0'-1 < s.charAt(i) && s.charAt(i) < '9'+1) {
                digit = i;
                digit_count++;
            }
            else if(s.charAt(i) == '.') {
                dot = i;
                dot_count++;
            }
            else if(s.charAt(i) == 'e' || s.charAt(i) == 'E') {
                e = i;
                e_count++;
            }
        }

        if(e_count == 1 && (e == 0 || e == s.length()-1)) return false; //no e at the ends
        if((dot_count == 1 && e_count == 1) && (e < dot)) return false; // no dots after e
        if(sign_ptr+digit_count+dot_count+e_count != s.length()) return false; //no letters
        if(dot_count > 1 || e_count > 1) return false; // only one e and one .
        if(digit_count == 0) return false; // digits must be found
        if(sign_ptr > 2) return false; // no more than 2 signs

        if(((e_count == 1) && digit > e)) return false; // digits mus be found before e

        for(int i=0; i<sign_ptr; i++) //signs can be only after e and at the beginning
            if(!(signs[i] == 0 || (e_count == 1 && signs[i] == e+1)) || signs[i] == s.length()-1) return false;

        return true;
    }
}
