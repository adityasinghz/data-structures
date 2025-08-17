class Solution {
public:
    string decodeString(string s) {
        stack<string>strStk;
        stack<int>strNum;
        string curr="";
        int num = 0;
        for(auto c: s){
            if(isdigit(c)){
                num = num *10 + (c - '0');
            }else if(c=='['){
               strStk.push(curr);
               strNum.push(num);
               curr = "";
               num = 0;
            }else if(c==']'){
                int n  = strNum.top(); strNum.pop();
                string p = strStk.top(); strStk.pop();
                string temp = "";
                for(int i=0;i<n;i++)temp+=curr;
                curr = p + temp;
            }else{
                curr+=c;
            }

        }
        return curr;
    }
};