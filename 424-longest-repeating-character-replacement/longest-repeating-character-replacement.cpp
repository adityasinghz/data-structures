class Solution {
public:
    int characterReplacement(string s, int k) {
       int left = 0;
       int n = s.size();
       int ans = 0;
       unordered_map<char,int>freq;
       for(int right=0; right < n; right++){
          int max_freq = 0;
          freq[s[right]]++;
          for(auto fre : freq){
             max_freq = max(max_freq, fre.second);
          }
          while((right - left + 1 - max_freq) > k){
            freq[s[left]]--;
            left++;
          }
          ans = max(ans, right - left + 1);
          
       }
       return ans;
    }
};