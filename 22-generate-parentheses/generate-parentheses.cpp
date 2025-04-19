class Solution {
public:
    bool validPara(string s){
         stack<char> stk;
    for (char c : s) {
        if (!stk.empty() && stk.top() == '(' && c == ')') {
            stk.pop();
        } else if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            // This means there's no matching '(' before it
            return false;
        }
    }
    return stk.empty();
    }
    void generatePara(int n,string s, vector<string>&ans){
       if(s.size()==2*n){
        if(validPara(s)) ans.push_back(s);
        return;
       }
       s.push_back('(');
       generatePara(n, s,ans);
       s.pop_back();
       s.push_back(')');
       generatePara(n, s,ans);
       s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        generatePara(n, s,ans);
        return ans;
    }
};