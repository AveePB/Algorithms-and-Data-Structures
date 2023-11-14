class Solution {
    public boolean isValid(String s) {
        Stack<Character> stck = new Stack<>();
        char[] str = s.toCharArray();
        int n = s.length();

        for(char c: str) {
            if((c == '(' || c == '[') || c == '{') {
                stck.push(c);
            }
            else {
                if(stck.isEmpty())
                    return false;
                if(c == ')' && stck.peek() == '(')
                    stck.pop();
                else if(c == ']' && stck.peek() == '[')
                    stck.pop();
                else if(c == '}' && stck.peek() == '{')
                    stck.pop();
                else
                    return false;
            }
        }
        return stck.isEmpty();
    }
}
