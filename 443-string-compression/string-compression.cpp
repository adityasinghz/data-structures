class Solution {
public:
    int compress(vector<char>& s) {
        int i = 0;
        int ct = 0;
        int indx=0;
        while(i < s.size()){
           char c = s[i];
           while(i<s.size()&&c==s[i]){ct++; i++;}
           s[indx++] = c;
           if(ct > 1){
                string str = to_string(ct);
                for(auto st : str) s[indx++]=st;
           }
           ct=0;
        }
        return indx;
    }
};