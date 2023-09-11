class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s;
        StringBuilder[] rows = new StringBuilder[numRows];
        char[] str = s.toCharArray();
        boolean is_increasing = true;
        int idx = 0;

        for(int i=0; i<numRows; i++) rows[i] = new StringBuilder();

        while (idx < str.length) {
            if(is_increasing) {
                int limit = Math.min(idx+numRows, str.length);
                for(int i=idx; i<limit; i++)
                    rows[i-idx].append(str[i]);
                is_increasing = false;
                idx += numRows;
            }
            else {
                int limit = Math.min(idx+numRows-2, str.length);
                for(int i=idx; i<limit; i++)
                    rows[numRows-(i-idx+2)].append(str[i]);
                is_increasing = true;
                idx += numRows-2;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(StringBuilder row: rows) sb.append(row);
        return sb.toString();
    }
}
