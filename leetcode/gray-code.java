class Solution {
    public List<Integer> grayCode(int n) {
        int len = (int)Math.pow(2, n), num = 0;
        List<Integer> ans = new ArrayList<>();
        
        for(int idx=0; idx<len; idx++) {
            //The current number is created by XOR(previous number, AND(index, -index))
            num ^= (idx & -idx);
            ans.add(num);
        }
        return ans;
    }
}
