class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int j = 0;
        int ans = 0;
        string str = to_string(num);
        int n = str.size();
        while( j < n ){
             int temp = 0;
             string sli = str.substr(j, k);
             if(sli.size()==k){
                temp = stoi(sli);
                if(temp && num%temp==0) ans++;
             }
             j++;
        }
        return ans;
    }
};