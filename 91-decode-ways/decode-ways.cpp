class Solution {
public:
    int depBackTrack(int i, string s,  vector<int>&dp, unordered_set<string>&st){
        if(i == s.size()) return 1;
        if(i > s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ways = 0;
        if(st.find(s.substr(i,1))!=st.end()){
           ways+=depBackTrack(i+1,s,dp,st);
        }
        if(i+1<s.size()&&st.find(s.substr(i,2))!=st.end()){
            ways+=depBackTrack(i+2,s,dp,st);
        }
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        unordered_set<string>st;
        vector<int>dp(s.size(),-1);
        for(int i=1;i<=26;i++) st.insert(to_string(i));
        return depBackTrack(0,s,dp,st);
    }
};