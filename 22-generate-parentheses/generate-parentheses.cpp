class Solution {
public:
    void dfs(int open, int close, int n, string params, vector<string>&res){
        if(open==close && open + close == 2*n){
            res.push_back(params);
            return;
        }
        if(open < n){
           dfs(open+1,close,n,params+"(",res);
        }
        if(close < open){
           dfs(open,close+1,n,params+")",res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        dfs(0,0,n,"",res);
        return res;
    }
};