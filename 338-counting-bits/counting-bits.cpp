class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int m = i;
            int ct = 0;
            while(m){
              if(m&1) ct++;
              m>>=1;
            }
            ans.push_back(ct);
        }
        return ans;
    }
};