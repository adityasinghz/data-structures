class Solution {
public:
    vector<string> split(string s, char delimeter){
       stringstream ss(s);
       vector<string>tokens;
       string token;
       while(getline(ss, token, delimeter)){
          tokens.push_back(token);
       } 
       return tokens;
    }

    string simplifyPath(string s) {
        vector<string>stk;
        vector<string> splittedS = split(s, '/');
        string res;
        int n = splittedS.size();
        for(int i=0;i<n;i++){
            if(splittedS[i]=="" || splittedS[i]==".") continue;
            else if(splittedS[i]=="..") {if(!stk.empty()) stk.pop_back();}
            else stk.push_back(splittedS[i]);
        }
        cout<<stk.size();
        for(auto s : stk) res+=("/" + s);
        return res.empty()? "/" : res;
    }
};