class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // first we're doing pre computation of sum
        if(k==0) return vector<int>(code.size());
        int i = 1;
        int j = k;
        int n =code.size();
        vector<int>ans(code.size());
        if(k < 0){
            i = (n + k)%n;
            j = n  - 1;
        }

        int sum = accumulate(code.begin() + i, code.begin() + j+1, 0);

        for(int indx = 0;indx < n; indx++){
            ans[indx] = sum;
            sum-=code[i];
            i = (i+1)%n;
            j = (j+1)%n;
            sum+=code[j];

        }

        return ans;
    }
};