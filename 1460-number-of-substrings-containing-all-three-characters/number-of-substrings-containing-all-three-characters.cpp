class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int a = -1;
        int b = -1;
        int c = -1;
        int ans = 0;
        unordered_map<char,int>freq;
                    
        while( j < n ){
            if(s[j] == 'a') a = j;
            if(s[j] == 'b') b = j;
            if(s[j] == 'c') c = j;

            j++;

            if(a == -1 || b == -1 || c == -1) continue;

            int indx = min(a, min(b,c));
            ans+=indx+1;
        }
        return ans;
    }
};