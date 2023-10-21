class Solution {
    boolean isConcatenation(Map<String, Integer> wanted, String str, int n, int l, int r) {
        Map<String, Integer> curr = new HashMap<>();
        while (l < r) {
            String substring = str.substring(l, l+n);
            int w_count = wanted.getOrDefault(substring, -1);
            int count = curr.getOrDefault(substring, 0) + 1;

            if(count > w_count) return false;
            curr.put(substring, count);
            l += n;
        }
        return true;
    }

    public List<Integer> findSubstring(String s, String[] words) {
        int k = words[0].length(), len = words.length * k;
        Map<String, Integer> w_dict = new HashMap<>();
        List<Integer> ans = new ArrayList<>();

        for(String word: words)
            w_dict.put(word, w_dict.getOrDefault(word, 0)+1);

        for(int i=0; i+len<=s.length(); i++) {
            if(!isConcatenation(w_dict, s, k, i, i+len)) continue;
            ans.add(i);
        }
        return ans;
    }
}
