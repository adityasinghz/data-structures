class Solution {
public:
    string removeStars(string s) {
        stack<char>stk;
        string ans;
        for(auto c : s){
            if(c=='*' && !stk.empty()) stk.pop();
            else stk.push(c);
        }
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};