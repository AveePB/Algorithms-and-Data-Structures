class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        StringBuilder sb = new StringBuilder();

        Arrays.sort(strs);

        char[] first = strs[0].toCharArray();
        char[] last = strs[n-1].toCharArray();
        int len = Math.min(first.length, last.length);
        for(int i=0; i<len; i++){
            if(first[i] == last[i])
                sb.append(first[i]);
            else
                return sb.toString();
        }

        return sb.toString();
    }
}
