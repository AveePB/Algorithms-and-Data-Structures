class Solution {
    List<String> res = new ArrayList<>();
    int n = 0;
    void constructString(StringBuilder sb, int state, int depth) {
        if(state < -this.n || state > 0)
            return;
        if(2*this.n == depth) {
            if(state == 0)
                this.res.add(sb.toString());
            return;
        }
        constructString(new StringBuilder(sb).append('('), state-1, depth+1);
        constructString(new StringBuilder(sb).append(')'), state+1, depth+1);
    }

    public List<String> generateParenthesis(int n) {
        this.n = n;
        constructString(new StringBuilder(), 0, 0);
        return this.res;
    }
}
