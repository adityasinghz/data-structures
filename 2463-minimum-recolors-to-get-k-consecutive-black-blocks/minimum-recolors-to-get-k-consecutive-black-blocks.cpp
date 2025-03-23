class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0;
        int j = 0;
        int n = blocks.size();
        int ct = 0;
        int ans = INT_MAX;
        while(j < n){
          if(blocks[j] == 'W' && j - i + 1 <= k){
             ct++;
          }
          if(j-i+1==k){
             ans=min(ans,ct);
             if(blocks[i]=='W' && ct > 0)ct--;
             i++;
          } 
          j++;
        }
        return ans;
    }
};