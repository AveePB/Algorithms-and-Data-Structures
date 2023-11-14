class Solution {
    public String intToRoman(int num) {
        String[] n1 = {"","I", "II", "III", "VI", "V", "IV", "IIV", "IIIV", "XI"};
        String[] n10 = {"","X", "XX", "XXX", "LX", "L", "XL", "XXL", "XXXL", "CX"};
        String[] n100 = {"","C", "CC", "CCC", "DC", "D", "CD", "CCD", "CCCD", "MC"};
        String[] n1000 = {"","M", "MM", "MMM"};

        StringBuilder sb = new StringBuilder();
        sb.append(n1[num%10]);
        num /= 10;
        sb.append(n10[num%10]);
        num /= 10;
        sb.append(n100[num%10]);
        num /= 10;
        sb.append(n1000[num%10]);

        return sb.reverse().toString();
    }
}
