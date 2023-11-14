class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if(s.length() == 0)
          return 0;
  
      int n = s.length(), ans{1}, len[n];
      map<int, int> taken;
      fill_n(len, n, 0);
  
      taken[s[0]] = 0;
      len[0] = 1; 
  
      for(int i=1; i<n; i++){
          int curr_char = s[i];
          if(taken.find(curr_char) == taken.end() || taken[curr_char] < i-len[i-1]){
              len[i] = len[i-1] + 1;
          }
          else if(taken[curr_char] == i-len[i-1] ){
              len[i] = len[i-1]; 
          }
          else{
              len[i] = i - taken[curr_char];
          }
          taken[curr_char] = i;
          ans = max(ans, len[i]);
          }
      return ans;
      }
};
