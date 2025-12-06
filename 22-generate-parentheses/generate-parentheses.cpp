class Solution {
public:
    void backtrack(int open, int close, int n, string param, vector<string>&res){
       if(open == close && 2*n==open+close){
          res.push_back(param);
          return;
       }
       if(open < n) backtrack(open+1,close,n,param+"(",res);
       if(close<open)backtrack(open,close+1,n,param+")",res);
    }
    vector<string> generateParenthesis(int n) {
       vector<string>res;
       backtrack(0,0,n,"",res);
       return res;     
    }
};