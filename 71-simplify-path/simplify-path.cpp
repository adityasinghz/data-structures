class Solution {
public:

vector<string> split(string s, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(s);
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

    string simplifyPath(string path) {
        vector<string> tokens = split(path, '/');
        stack<string>stk,stk2;
        string res;
        for(auto token : tokens){
            if(token=="" || token==".") continue;
            else if(token==".."){
             if(!stk.empty()) stk.pop();
            }else stk.push(token);
        }

         while(!stk.empty()){
            stk2.push(stk.top());
            stk.pop();
        }

        while(!stk2.empty()){
            res+=stk2.top();
            res+='/';
            stk2.pop();
        }
        if(!res.empty()) res.pop_back();
       
        return "/"+res;
    }
};