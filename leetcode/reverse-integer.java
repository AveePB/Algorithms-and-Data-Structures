class Solution {
    public boolean isCorrect(int num) {
        if(-1000000000 <= num && num <= 1000000000)
            return true;
        int max_digits = 2147483412;

        if(-2000000000 < num && num < 2000000000)
            max_digits = 1463847412;

        while (num != 0) {
            if(Math.abs(num%10) <= max_digits%10) {
                max_digits /= 10;
                num /= 10;
                continue;
            }
            return false;
        }
        return true;
    }
    public int reverse(int x) {
        if(!isCorrect(x))
            return 0;
        int res = 0;
        while (x != 0) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
}
