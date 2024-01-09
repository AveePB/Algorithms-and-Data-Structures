class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder ans = new StringBuilder();
        List<Character> arr = new ArrayList<>();
        int div = 1;

        for(int i=1; i<=n; i++){
            arr.add((char)('0'+i));
            div *= i;
        }
        div /= n;
        k -= 1;

        while(true) {
            int idx = k/div;
            ans.append(arr.get(idx));
            arr.remove(idx);

            if(arr.size() == 0) break;

            k %= div;
            div /= arr.size();
        }
        return ans.toString();
    }
}
