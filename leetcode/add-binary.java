class Solution {
    public String addBinary(String a, String b) {
        int i = a.length()-1, j = b.length()-1, carry = 0;
        StringBuilder sb = new StringBuilder();

        while (i >= 0 || j >= 0) {
            if(i >= 0 && a.charAt(i--) == '1') carry++;
            if(j >= 0 && b.charAt(j--) == '1') carry++;
            sb.append((char) ('0' + carry%2));
            carry /= 2;
        }
        if(carry != 0) sb.append((char) ('0' + carry%2));

        return sb.reverse().toString();
    }
}
