class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stck = new Stack<>();
        char[] str = s.toCharArray();
        int res = 0, left = -1; //left is one idx before the start of an index
        for(int i=0; i<str.length; i++) {
            if(str[i] == '(')
                stck.add(i);
            else {
                if(!stck.isEmpty()){ //stack is not empty
                    stck.pop();
                    if(!stck.isEmpty()) //there are unclosed '('
                        res = Math.max(res, i-stck.peek()); //valid string length will start after first unclosed (
                    else
                        res = Math.max(res, i-left); //stack is empty, so we use left to find the beginning
                    continue;
                }
                left = i; //there is extra ')', so we set new left
            }
        }
        return res;
    }
}
