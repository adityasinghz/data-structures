class Solution {
public:
    int myAtoi(string s) {
        string temp;
        int n = s.size();
        int j = 0;
        while(j < n){
         if(s[j]!=' ')break;
         j++;
        }
        if(s[j]=='+' || s[j]=='-')temp+=s[j++];
        for(int i=j;i<s.size();i++){
            char c = s[i];
            if( (c >= 'a' && c <='z') || (c>='A' && c<='Z') || c=='-' || c=='+'  || c==' ' || c=='.' ){
              break;
            }else{
                temp+=c;
            }
        }
        long long int ans = 0;
        int i = 0;
        while(i<temp.size()){
              if(temp[i]=='+' || temp[i]=='-'){
               i++;
               continue;
              }
              if(ans*10 + (temp[i] - '0') >= INT_MAX && temp[0]!='-') return INT_MAX;
              if((ans*10 + (temp[i] - '0'))*-1 <= INT_MIN && temp[0]=='-') return INT_MIN;
              ans = ans*10 + temp[i] - '0';
              i++;
        }
        cout<<temp<<'\n';
        return temp[0]=='-'?-ans:ans;
    }
};