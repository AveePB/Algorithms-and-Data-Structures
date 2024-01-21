public class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        digits[n-1] += 1;

        for(int i=n-1; i>0; i--){
            int inc = digits[i] / 10;
            digits[i-1] += inc;
            digits[i] %= 10;
        }

        if(digits[0] > 9) {
            int[] ext_digits = new int[n+1];
            ext_digits[0] = 1;
            ext_digits[1] = digits[0] % 10;
            for(int i=2; i<n; i++)
                ext_digits[i] = digits[i-1];
            return ext_digits;
        }
        return digits;
    }
}
