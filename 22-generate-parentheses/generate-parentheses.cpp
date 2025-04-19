class Solution {
public:
    void dfs(int open, int close, int n, string s, vector<string>&ans){
        if(open == close && open+close==2*n){
           ans.push_back(s);
           return;
        }
        if(open<n){
          dfs(open+1,close,n,s+"(",ans);
        }
        if(close<open){
          dfs(open,close+1,n,s+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        dfs(0,0,n,"",ans);
        return ans;
    }
};