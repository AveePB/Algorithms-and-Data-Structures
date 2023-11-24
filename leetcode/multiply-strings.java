class Solution {
    public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")) return "0";

        int n = num1.length(), m = num2.length();
        int[] res = new int[n+m];

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                res[i+j+1] += (num1.charAt(i)-'0') * (num2.charAt(j)-'0');
                res[i+j] += res[i+j+1] / 10;
                res[i+j+1] %= 10;
            }
        }
        int idx = 0;
        StringBuilder ans = new StringBuilder();
        while (res[idx] == 0) idx++;
        while (idx < res.length) ans.append(String.valueOf(res[idx++]));
        return ans.toString();
    }
}
