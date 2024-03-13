class Solution {
    private void backtracking(List<String> ans, StringBuilder sb, String s, int depth, int idx) {
        if(depth == 4 && s.length()+4 == sb.length()) {
            ans.add(new StringBuilder(sb).deleteCharAt(0).toString());
            return;
        }

        if(idx+1 <= s.length()){
            int start = sb.length();
            backtracking(ans, sb.append('.').append(s.charAt(idx)) , s, depth+1, idx+1);
            sb.delete(start, sb.length());
        }

        if(idx+2 <= s.length()) {
            int val = (s.charAt(idx) - '0') * 10 + (s.charAt(idx)- '0');
            if(10 <= val){
                int start = sb.length();
                backtracking(ans,  sb.append('.').append(s, idx, idx+2) , s, depth+1, idx+2);
                sb.delete(start, sb.length());
            }
        }

        if(idx+3 <= s.length()) {
            int val = (s.charAt(idx) - '0') * 100 + (s.charAt(idx+1) - '0') * 10 + (s.charAt(idx+2)- '0');
            if(100 <= val && val <= 255) {
                int start = sb.length();
                backtracking(ans, sb.append('.').append(s, idx, idx+3) , s, depth+1, idx+3);
                sb.delete(start, sb.length());
            }
        }
    }

    public List<String> restoreIpAddresses(String s) {
        StringBuilder sb = new StringBuilder();
        List<String> ans = new ArrayList<>();

        if(s.length() > 12) return new ArrayList<>();

        backtracking(ans, sb, s, 0, 0);
        return ans;
    }
}
