public class Solution {
    List<String> ans = new ArrayList<>();
    char [][] btn = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j', 'k', 'l'},
            {'m','n','o'}, {'p','q','r','s'}, {'t', 'u', 'v'}, {'w','x','y','z'}};
    String digits;

    void backtracking(StringBuilder sb, int idx){
        if(idx == this.digits.length()){
            if(sb.toString().length() > 0)
                this.ans.add(sb.toString());
            return;
        }
        
        for(char c: this.btn[this.digits.charAt(idx)-50])
            backtracking(new StringBuilder(sb).append(c), idx+1);
    }


    public List<String> letterCombinations(String digits) {
        this.digits = digits;
        backtracking(new StringBuilder(), 0);
        return this.ans;
    }
}
